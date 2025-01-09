#include "../../brick_game/tetris/brickgame.h"

void print_field(GameInfo_t *info) {
  mvaddch(0, 0, ACS_ULCORNER);
  for (int j = 1; j <= FIELD_X; j++) {
    mvaddch(0, j, ACS_HLINE);
  }
  mvaddch(0, FIELD_X + 1, ACS_URCORNER);
  for (int i = 1; i <= FIELD_Y; i++) {
    mvaddch(i, 0, ACS_VLINE);
    for (int j = 1; j <= FIELD_X; j++) {
      info->field[i][j] ? mvaddch(i, j, ACS_BLOCK) : mvaddch(i, j, ' ');
    }
    mvaddch(i, FIELD_X + 1, ACS_VLINE);
  }
  mvaddch(FIELD_Y + 1, 0, ACS_LLCORNER);
  for (int j = 1; j <= FIELD_X; j++) {
    mvaddch(FIELD_Y + 1, j, ACS_HLINE);
  }
  mvaddch(FIELD_Y + 1, FIELD_X + 1, ACS_LRCORNER);
}

void print_figure(GameInfo_t *info, int shape[4][4], int start_y, int start_x) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (shape[i][j] == 1) info->field[start_y + i][start_x + j] = 1;
    }
  }
}

void stay_figure(GameInfo_t *info, int shape[4][4], int start_y, int start_x) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (shape[i][j] == 1) info->field[start_y + i][start_x + j] = 2;
    }
  }
}
void spawn_figure(GameInfo_t *info, Figure_t *figures, sqlite3 *db) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figures->current_shape[i][j] = info->next[i][j];
    }
  }
  generateRandomFigure(info, figures);
  figures->x = (FIELD_X / 2);
  figures->y = 2;
  if (!check_drop_figure(info, figures)) {
    mvprintw(4, FIELD_X + 5, "Game Over!");
    mvprintw(10, FIELD_X + 5, "Press 'q' to quit");
    print_field(info);
    int ch;
    while ((ch = getch()) != 'q' && ch != 'Q') {
    }
    quitGame(info, db);
  } else
    print_figure(info, figures->current_shape, figures->y, figures->x);
}

void print_info(GameInfo_t *game) {
  mvprintw(0, FIELD_X + 5, "Score: %d", game->score);
  mvprintw(1, FIELD_X + 5, "Level: %d", game->level);
  mvprintw(2, FIELD_X + 5, "High Score: %d", game->high_score);
  mvprintw(3, FIELD_X + 5, "Next:");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      game->next[i][j] ? mvaddch(5 + i, FIELD_X + 10 + j, ACS_BLOCK)
                       : mvaddch(5 + i, FIELD_X + 10 + j, ' ');
    }
  }
}

void print_start() {
  mvaddch(0, 0, ACS_ULCORNER);
  for (int j = 1; j <= FIELD_X; j++) {
    mvaddch(0, j, ACS_HLINE);
  }
  mvaddch(0, FIELD_X + 1, ACS_URCORNER);
  for (int i = 1; i <= FIELD_Y; i++) {
    mvaddch(i, 0, ACS_VLINE);
    for (int j = 1; j <= FIELD_X * 2; j++) {
      mvaddch(i, j, ' ');
    }
    mvaddch(i, FIELD_X + 1, ACS_VLINE);
  }
  mvaddch(FIELD_Y + 1, 0, ACS_LLCORNER);
  for (int j = 1; j <= FIELD_X; j++) {
    mvaddch(FIELD_Y + 1, j, ACS_HLINE);
  }
  mvaddch(FIELD_Y + 1, FIELD_X + 1, ACS_LRCORNER);

  mvprintw(10, 1, "Press Enter");
  mvprintw(11, 1, "to Start Game!");
}