#include "brickgame.h"

void generate_field(GameInfo_t *info) {
  info->field = calloc(FIELD_Y + 2, sizeof(int *));
  for (int i = 0; i <= FIELD_Y + 1; i++) {
    info->field[i] = calloc(FIELD_X + 2, sizeof(int));
  }
  for (int i = 0; i <= FIELD_Y + 1; i++) {
    for (int j = 0; j <= FIELD_X + 1; j++) {
      if (i == 0 || i == FIELD_Y + 1 || j == 0 || j == FIELD_X + 1) {
        info->field[i][j] = 2;
      }
    }
  }
  info->next = calloc(4, sizeof(int *));
  for (int i = 0; i < 4; i++) {
    info->next[i] = calloc(4, sizeof(int));
  }
}

void init_Figures(Figure_t *figure) {
  int I_shape_f[4][4] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int J_shape_f[4][4] = {
      {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int L_shape_f[4][4] = {
      {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int O_shape_f[4][4] = {
      {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int S_shape_f[4][4] = {
      {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int T_shape_f[4][4] = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int Z_shape_f[4][4] = {
      {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure->shapes[0][i][j] = I_shape_f[i][j];
      figure->shapes[1][i][j] = J_shape_f[i][j];
      figure->shapes[2][i][j] = L_shape_f[i][j];
      figure->shapes[3][i][j] = O_shape_f[i][j];
      figure->shapes[4][i][j] = S_shape_f[i][j];
      figure->shapes[5][i][j] = T_shape_f[i][j];
      figure->shapes[6][i][j] = Z_shape_f[i][j];
    }
  }
}

bool check_drop_figure(GameInfo_t *game, Figure_t *figure) {
  bool drop = true;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->current_shape[i][j] == 1) {
        if (figure->y + i + 1 >= FIELD_Y) {
          drop = false;
        }
        if (game->field[figure->y + i + 2][figure->x + j] == 2) {
          drop = false;
        }
      }
    }
  }
  return drop;
}

GameInfo_t updateCurrentState(GameInfo_t *info, Figure_t *figure, sqlite3 *db) {
  if (check_drop_figure(info, figure)) {
    remove_figure(info, figure);
    figure->y += 1;
  } else {
    remove_figure(info, figure);
    figure->y += 1;
    print_figure(info, figure->current_shape, figure->y, figure->x);
    stay_figure(info, figure->current_shape, figure->y, figure->x);
    spawn_figure(info, figure, db);
  }
  return *info;
}

void remove_figure(GameInfo_t *info, Figure_t *figure) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->current_shape[i][j] != 0)
        info->field[figure->y + i][figure->x + j] = 0;
    }
  }
}

bool can_move(GameInfo_t *info, Figure_t *figure, int dy, int dx) {
  bool move = true;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (figure->current_shape[i][j] != 0) {
        int new_y = figure->y + i + dy;
        int new_x = figure->x + j + dx;

        if (new_y < 1 || new_y >= FIELD_Y + 1 || new_x < 1 ||
            new_x >= FIELD_X + 1)
          move = false;
        if (info->field[new_y][new_x] != 0) move = false;
      }
    }
  }
  return move;
}

void clear_full_lines(GameInfo_t *info) {
  int lines_cleared = 0;
  for (int i = FIELD_Y; i >= 1; i--) {
    if (check_line(info, i)) {
      lines_cleared++;
      for (int k = i; k >= 1; k--) {
        for (int j = 0; j <= FIELD_X; j++) {
          info->field[k][j] = (k == 1) ? 0 : info->field[k - 1][j];
        }
      }
      i++;
    }
  }
  switch (lines_cleared) {
    case 1:
      info->score += 100;
      break;
    case 2:
      info->score += 300;
      break;
    case 3:
      info->score += 700;
      break;
    case 4:
      info->score += 1500;
      break;
    default:
      break;
  }
  change_level(info);
}

bool check_line(GameInfo_t *info, int i) {
  bool line = true;
  for (int j = 1; j <= FIELD_X; j++) {
    if (info->field[i][j] == 0) {
      line = false;
    }
  }
  return line;
}

void rotate_figure(GameInfo_t *info, Figure_t *figure) {
  int temp[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      temp[j][i] = figure->current_shape[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure->current_shape[i][j] = temp[i][3 - j];
    }
  }

  if (check_drop_figure(info, figure))
    stay_figure(info, figure->current_shape, figure->y, figure->x);
  else {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        figure->current_shape[i][j] = temp[j][i];
      }
    }
  }
}

bool can_rotate(GameInfo_t *info, Figure_t *figure) {
  bool rotate = true;
  int temp[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      temp[j][i] = figure->current_shape[i][j];
    }
  }
  if (equal_matrix(temp, figure->shapes)) rotate = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      int tmp = temp[i][j];
      temp[i][j] = temp[i][3 - j];
      temp[i][3 - j] = tmp;
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (temp[i][j] != 0) {
        int new_x = figure->x + j;
        int new_y = figure->y + i;

        if (new_x < 1 || new_x > FIELD_X || new_y > FIELD_Y) rotate = false;

        if (info->field[new_y][new_x] != 0) rotate = false;
      }
    }
  }

  if (rotate) {
    remove_figure(info, figure);
  }

  return rotate;
}

bool equal_matrix(int data[4][4], int src[3][4][4]) {
  bool equal = true;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (data[j][i] != src[3][i][j]) {
        equal = false;
      }
    }
  }
  return equal;
}

void generateRandomFigure(GameInfo_t *info, Figure_t *figures) {
  int piece = rand() % 7;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      info->next[i][j] = figures->shapes[piece][i][j];
    }
  }
}

void free_matrix(GameInfo_t *info) {
  for (int i = 0; i <= FIELD_Y + 1; i++) {
    free(info->field[i]);
  }
  free(info->field);
  for (int i = 0; i < 4; i++) {
    free(info->next[i]);
  }
  free(info->next);
}

void change_level(GameInfo_t *info) {
  const int score_const = 600;
  for (int i = 0; i <= 9; i++) {
    if (info->level == i && info->score >= (i + 1) * score_const) {
      info->speed -= 10;
      info->level += 1;
    }
  }
}