#include "brickgame.h"

int main() {
  setlocale(LC_ALL, "");
  sqlite3 *db;
  GameInfo_t tetris;
  Figure_t figure;
  UserAction_t action = 5;
  srand(time(NULL));
  int game = GAME_ON;
  sqlite3_open("record.db", &db);
  create_table_if_not_exists(db);
  tetris.high_score = sql_high(db), tetris.score = 0, tetris.level = 0,
  tetris.pause = 0, tetris.speed = GAME_SPEED * 2;
  ncurses_func();

  init_game(&tetris, &figure, action, db);

  noecho();
  timeout(60);

  game_loop(&tetris, &figure, action, game, db);

  return 0;
}
