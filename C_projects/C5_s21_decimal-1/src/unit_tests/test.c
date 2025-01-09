#include "test.h"

int main(void) {
  run_tests();
  return 0;
}

void run_tests(void) {
  Suite *list_cases[] = {
      suite_s21_from_int_to_decimal(), suite_s21_from_decimal_to_int(),
      //  suite_s21_utulity_functions_test(),
      suite_s21_from_decimal_to_float(), suite_s21_from_float_to_decimal(),
      s21_add_cases(), s21_sub_cases(), s21_mul_cases(), s21_div_cases(),
      //  suite_s21_is_equal_test(),
      is_equal_suite1(), is_equal_suite2(), is_equal_suite3(),
      is_equal_suite4(), is_equal_suite5(), is_equal_suite6(),
      is_equal_suite7(), is_equal_suite8(), is_equal_suite9(),
      is_equal_suite10(), is_equal_suite11(), is_equal_suite12(),
      is_equal_suite13(), is_equal_suite14(), is_equal_suite15(),
      is_equal_suite16(), suite_s21_is_not_equal_test(),
      //  suite_s21_is_greater_test(),
      is_greater_suite1(), is_greater_suite2(), is_greater_suite3(),
      is_greater_suite4(), is_greater_suite5(), is_greater_suite6(),
      is_greater_suite7(), is_greater_suite8(), is_greater_suite9(),
      is_greater_suite10(), is_greater_suite11(), is_greater_suite12(),
      is_greater_suite13(), is_greater_suite14(), is_greater_suite15(),
      is_greater_suite16(),

      suite_s21_is_less_test(), suite_s21_is_greater_or_equal_test(),
      suite_s21_is_less_or_equal_test(), floor_suite(), truncate_suite(),
      negate_suite(),
      //  round_suite(),
      round_suite0(), round_suite1(), round_suite2(), round_suite3(), NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) putchar('\n');
  printf("CURRENT TEST: %d\n", counter_testcase);
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
