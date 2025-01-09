#include "brickgame.h"

void game_loop(GameInfo_t* tetris, Figure_t* figure, UserAction_t action,
               int game, sqlite3* db) {
  while (game) {
    int ch = getch();
    if (ch == 'p' || ch == 'P') {
      togglePause(tetris);
    }

    if (tetris->pause) {
      continue;
    }
    *tetris = updateCurrentState(tetris, figure, db);
    switch (ch) {
      case 'Q':
      case 'q':
        action = Terminate;
        break;
      case KEY_LEFT:
        action = Left;
        break;
      case KEY_RIGHT:
        action = Right;
        break;
      case KEY_DOWN:
        action = Down;
        break;
      case ' ':
        action = Action;
        break;
      default:
        break;
    }
    userInput(action, tetris, figure, db);
    action = 0;
    clear_full_lines(tetris);

    print_figure(tetris, figure->current_shape, figure->y, figure->x);
    print_field(tetris);
    print_info(tetris);

    refresh();
    napms(tetris->speed);
  }
}

void init_game(GameInfo_t* tetris, Figure_t* figure, UserAction_t action,
               sqlite3* db) {
  start_game(action);
  generate_field(tetris);
  init_Figures(figure);
  generateRandomFigure(tetris, figure);
  spawn_figure(tetris, figure, db);
  print_field(tetris);
  print_info(tetris);
}

void ncurses_func() {
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  cbreak();
  noecho();
}

void start_game(UserAction_t action) {
  print_start();
  refresh();
  while ((action = getch()) != '\n') {
    if (action == 'q' || action == 'Q') {
      endwin();
      exit(0);
    }
  }
  clear();
}