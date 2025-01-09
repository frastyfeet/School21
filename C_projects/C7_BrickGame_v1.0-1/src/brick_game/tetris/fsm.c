#include "brickgame.h"

void userInput(UserAction_t action, GameInfo_t *tetris, Figure_t *figure,
               sqlite3 *db) {
  switch (action) {
    case Terminate:
      quitGame(tetris, db);
      break;

    case Pause:
      togglePause(tetris);
      break;

    case Left:
      if (can_move(tetris, figure, 0, -1)) {
        figure->x -= 1;
      }
      break;

    case Right:
      if (can_move(tetris, figure, 0, 1)) {
        figure->x += 1;
      }
      break;
    case Down:
      down_figure(tetris, figure, db);
      break;

    case Action:
      if (can_rotate(tetris, figure)) {
        rotate_figure(tetris, figure);
      }
      break;

    default:
      break;
  }
}

void quitGame(GameInfo_t *game, sqlite3 *db) {
  sql_insert(game, db);
  sqlite3_close(db);
  free_matrix(game);
  endwin();
  printf("Спасибо за игру!\n");
  exit(0);
}

void togglePause(GameInfo_t *info) {
  info->pause = !info->pause;

  if (info->pause) {
    mvprintw(3, FIELD_X + 5, "Pause");
    refresh();
  } else {
    mvprintw(3, FIELD_X + 5, "     ");
    refresh();
  }
}

void down_figure(GameInfo_t *info, Figure_t *figure, sqlite3 *db) {
  while (check_drop_figure(info, figure)) {
    *info = updateCurrentState(info, figure, db);
  }
}