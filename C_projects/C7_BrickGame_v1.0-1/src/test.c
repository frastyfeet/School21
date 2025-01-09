#include <check.h>

#include "./brick_game/tetris/brickgame.h"

START_TEST(test_generate_field) {
  GameInfo_t info;
  generate_field(&info);

  ck_assert_ptr_ne(info.field, NULL);
  ck_assert_int_eq(info.field[0][0], 2);
  ck_assert_int_eq(info.field[FIELD_Y + 1][FIELD_X + 1], 2);
  ck_assert_int_eq(info.field[FIELD_Y][FIELD_X], 0);
}
END_TEST

START_TEST(test_init_Figures) {
  Figure_t figure;
  init_Figures(&figure);

  ck_assert_int_eq(figure.shapes[0][0][0], 0);
  ck_assert_int_eq(figure.shapes[1][1][0], 1);
  ck_assert_int_eq(figure.shapes[2][1][1], 1);
  ck_assert_int_eq(figure.shapes[3][1][1], 1);
}
END_TEST

START_TEST(test_check_drop_figure) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);
  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(check_drop_figure(&game, &figure), true);

  figure.y = FIELD_Y - 2;
  print_figure(&game, figure.current_shape, figure.y, figure.x);
  ck_assert_int_eq(check_drop_figure(&game, &figure), false);  // fixed
}
END_TEST

START_TEST(test_updateCurrentState) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);

  game = updateCurrentState(&game, &figure, NULL);
  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(game.field[figure.y + 1][figure.x], 1);
}
END_TEST

START_TEST(test_remove_figure) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);

  spawn_figure(&game, &figure, NULL);

  remove_figure(&game, &figure);
  ck_assert_int_eq(game.field[figure.y][figure.x], 0);
}
END_TEST

START_TEST(test_can_move) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);

  print_figure(&game, figure.current_shape, figure.y,
               figure.x);  // Пример: I-форма

  ck_assert_int_eq(can_move(&game, &figure, 2, 2), true);

  ck_assert_int_eq(can_move(&game, &figure, 0, FIELD_X + 1), false);
}
END_TEST
START_TEST(test_clear_full_lines) {
  GameInfo_t game;

  generate_field(&game);

  for (int i = 1; i <= FIELD_X; i++) {
    game.field[FIELD_Y][i] = 1;
  }

  clear_full_lines(&game);

  ck_assert_int_eq(game.field[FIELD_Y][1], 0);
}
END_TEST
START_TEST(test_rotate_figure) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  figure.y = 4;
  figure.x = 5;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure.current_shape[i][j] = figure.shapes[0][i][j];
    }
  }
  if (can_rotate(&game, &figure)) rotate_figure(&game, &figure);
  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(figure.current_shape[0][0], 0);
  ck_assert_int_eq(figure.current_shape[0][2], 1);
}
END_TEST

START_TEST(test_free_matrix) {
  GameInfo_t game;
  generate_field(&game);

  free_matrix(&game);
}
END_TEST
START_TEST(test_print_field) {
  GameInfo_t info;
  generate_field(&info);
  print_field(&info);
}
END_TEST

START_TEST(test_print_info) {
  GameInfo_t game;
  generate_field(&game);
  game.score = 100;
  game.level = 2;
  game.high_score = 500;

  print_info(&game);

  ck_assert_int_eq(game.score, 100);
  ck_assert_int_eq(game.level, 2);
  ck_assert_int_eq(game.high_score, 500);
}
END_TEST

START_TEST(test_print_start) { print_start(); }
END_TEST

START_TEST(test_userInput_terminate) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);

  userInput(Terminate, &game, &figure, NULL);

  ck_assert_ptr_null(game.field);
}
END_TEST

START_TEST(test_userInput_left) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);
  remove_figure(&game, &figure);
  userInput(Left, &game, &figure, NULL);
  remove_figure(&game, &figure);

  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(figure.x, 4);
}
END_TEST

START_TEST(test_userInput_right) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);
  remove_figure(&game, &figure);
  userInput(Right, &game, &figure, NULL);
  remove_figure(&game, &figure);

  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(figure.x, 6);
}
END_TEST

START_TEST(test_userInput_down) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);
  remove_figure(&game, &figure);
  userInput(Down, &game, &figure, NULL);
  remove_figure(&game, &figure);

  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(figure.y, 18);
}
END_TEST

START_TEST(test_togglePause) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);

  togglePause(&game);
  ck_assert_int_eq(game.pause, 1);

  togglePause(&game);
  ck_assert_int_eq(game.pause, 0);
}
END_TEST

START_TEST(test_userInput_action) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  figure.y = 4;
  figure.x = 5;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure.current_shape[i][j] = figure.shapes[0][i][j];
    }
  }
  userInput(Action, &game, &figure, NULL);
  print_figure(&game, figure.current_shape, figure.y, figure.x);

  ck_assert_int_eq(figure.current_shape[0][0], 0);
  ck_assert_int_eq(figure.current_shape[0][2], 1);
}
END_TEST

START_TEST(test_userInput_pause) {
  GameInfo_t game;
  Figure_t figure;

  generate_field(&game);
  init_Figures(&figure);
  generateRandomFigure(&game, &figure);

  spawn_figure(&game, &figure, NULL);

  userInput(Pause, &game, &figure, NULL);
  ck_assert_int_eq(game.pause, 1);

  userInput(Pause, &game, &figure, NULL);
  ck_assert_int_eq(game.pause, 0);
}
END_TEST
int main(void) {
  int number_failed;
  Suite *s = suite_create("Tetris Tests");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_generate_field);
  tcase_add_test(tc_core, test_init_Figures);
  tcase_add_test(tc_core, test_check_drop_figure);
  tcase_add_test(tc_core, test_updateCurrentState);
  tcase_add_test(tc_core, test_remove_figure);
  tcase_add_test(tc_core, test_can_move);
  tcase_add_test(tc_core, test_clear_full_lines);
  tcase_add_test(tc_core, test_rotate_figure);
  tcase_add_test(tc_core, test_free_matrix);

  tcase_add_test(tc_core, test_print_field);
  tcase_add_test(tc_core, test_print_info);
  tcase_add_test(tc_core, test_print_start);

  tcase_add_test(tc_core, test_userInput_terminate);
  tcase_add_test(tc_core, test_userInput_left);
  tcase_add_test(tc_core, test_userInput_right);
  tcase_add_test(tc_core, test_userInput_down);
  tcase_add_test(tc_core, test_togglePause);
  tcase_add_test(tc_core, test_userInput_action);
  tcase_add_test(tc_core, test_userInput_pause);

  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}
