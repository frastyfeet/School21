#include "../brickgame.h"
#include "sqlite3.h"

int sql_high(sqlite3 *db) {
  char *err_msg = 0;
  const char *sql = "SELECT MAX(result) FROM record";
  int high_score = 0;
  sqlite3_exec(db, sql, callback, &high_score, &err_msg);
  return high_score;
}

int callback(void *data, int argc, char **argv, char **azColName) {
  **azColName = 0;
  if (argc > 0 && argv[0]) {
    *(int *)data = atoi(argv[0]);
  }
  return 0;
}

void sql_insert(GameInfo_t *info, sqlite3 *db) {
  char *err_msg = 0;
  char sql[50];
  sprintf(sql, "INSERT INTO record VALUES (%d)", info->score);
  sqlite3_exec(db, sql, 0, 0, &err_msg);
}

void create_table_if_not_exists(sqlite3 *db) {
  char *err_msg = 0;
  const char *sql = "CREATE TABLE IF NOT EXISTS record (result INTEGER);";
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(err_msg);
  }
}
