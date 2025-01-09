#ifndef BRICKGAME_H
#define BRICKGAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#include <locale.h>
#include "./sql/sqlite3.h"


#define FIELD_X 10
#define FIELD_Y 20
#define GAME_SPEED 60

#define GAME_ON 1
#define GAME_OVER 0
#define HOLD_INTERVAL 100


typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

typedef struct {
    int shapes[7][4][4];
    int x;
    int y;
    int current_shape[4][4]; 
 } Figure_t;

// loop
void game_loop(GameInfo_t* tetris, Figure_t* figure, UserAction_t action, int game, sqlite3* db);
void init_game(GameInfo_t *tetris, Figure_t *figure, UserAction_t action,sqlite3* db);
void ncurses_func();

//front
void print_field(GameInfo_t *info);
void spawn_figure(GameInfo_t *info, Figure_t *figures, sqlite3 *db);
void print_figure(GameInfo_t *info, int shape[4][4], int start_y, int start_x);
void stay_figure(GameInfo_t *info, int shape[4][4], int start_y, int start_x);
void print_info(GameInfo_t *game);
void print_start();

//back
GameInfo_t updateCurrentState(GameInfo_t *info, Figure_t *figure,sqlite3* db);
void generate_field(GameInfo_t *info);
void init_Figures(Figure_t *figure);
void remove_figure(GameInfo_t *game, Figure_t *figure);
bool check_drop_figure(GameInfo_t *game, Figure_t *figure);
bool can_fall(GameInfo_t *game, Figure_t *figure);
void fix_figure(GameInfo_t *game, Figure_t *figure);
bool can_move(GameInfo_t *info, Figure_t *figure, int dy, int dx);
void move_figures(GameInfo_t *info, Figure_t *figure, int ch);
bool check_line(GameInfo_t *info, int i);
void clear_full_lines(GameInfo_t *info);
void change_level(GameInfo_t *info);
void rotate_figure(GameInfo_t *info,Figure_t *figure);
bool can_rotate(GameInfo_t *info, Figure_t *figure);
void quitGame(GameInfo_t *game, sqlite3 *db);
void togglePause(GameInfo_t *info);
bool equal_matrix(int data[4][4],int src[3][4][4]);
void generateRandomFigure(GameInfo_t *info, Figure_t *figures);
void free_matrix(GameInfo_t *info);
void start_game(UserAction_t action);
void down_figure(GameInfo_t *info, Figure_t *figure, sqlite3 *db);
void print_matrix_field(GameInfo_t *info);

//fsm
void userInput(UserAction_t action, GameInfo_t *tetris, Figure_t *figure,sqlite3 *db);

// db
void create_table_if_not_exists(sqlite3 *db);
int sql_high(sqlite3 *db);
void sql_insert(GameInfo_t* info, sqlite3 *db);
int callback(void *data, int argc, char **argv, char **azColName);

#endif
