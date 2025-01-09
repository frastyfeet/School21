#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SCALE_1 0x10000
#define SCALE_3 0x30000
#define SIGN_MINUS_0x 0x80000000
#define SCALE_1_SIGN_MINUS 0x80010000
#define SCALE_3_SIGN_MINUS 0x80030000
#define SCALE_20_SIGN_MINUS 0x80140000

#define TEST_OTHER_OK 0
#define TEST_OTHER_ERROR 1

Suite *suite_s21_from_int_to_decimal(void);
Suite *suite_s21_from_decimal_to_int(void);
Suite *suite_s21_utulity_functions_test(void);
Suite *s21_add_cases(void);
Suite *s21_sub_cases(void);
Suite *s21_mul_cases(void);
Suite *s21_div_cases(void);
Suite *suite_s21_is_equal_test(void);
Suite *suite_s21_is_not_equal_test(void);
Suite *suite_s21_is_greater_test(void);
Suite *suite_s21_is_less_test(void);
Suite *suite_s21_is_greater_or_equal_test(void);
Suite *suite_s21_is_less_or_equal_test(void);
Suite *floor_suite(void);
Suite *round_suite(void);
Suite *truncate_suite(void);
Suite *negate_suite(void);

Suite *round_suite0(void);
Suite *round_suite1(void);
Suite *round_suite2(void);
Suite *round_suite3(void);

Suite *is_equal_suite1(void);
Suite *is_equal_suite2(void);
Suite *is_equal_suite3(void);
Suite *is_equal_suite4(void);
Suite *is_equal_suite5(void);
Suite *is_equal_suite6(void);
Suite *is_equal_suite7(void);
Suite *is_equal_suite8(void);
Suite *is_equal_suite9(void);
Suite *is_equal_suite10(void);
Suite *is_equal_suite11(void);
Suite *is_equal_suite12(void);
Suite *is_equal_suite13(void);
Suite *is_equal_suite14(void);
Suite *is_equal_suite15(void);
Suite *is_equal_suite16(void);

void test_is_equal(s21_decimal decimal1, s21_decimal decimal2, int check);
void test_negate(s21_decimal decimal, s21_decimal decimal_check);
void test_floor(s21_decimal decimal, s21_decimal decimal_check);
void test_round(s21_decimal decimal, s21_decimal decimal_check);
void test_truncate(s21_decimal decimal, s21_decimal decimal_check);

Suite *s21_div_cases(void);

Suite *suite_s21_from_decimal_to_float(void);
Suite *suite_s21_from_float_to_decimal(void);

Suite *is_greater_suite1(void);
Suite *is_greater_suite2(void);
Suite *is_greater_suite3(void);
Suite *is_greater_suite4(void);
Suite *is_greater_suite5(void);
Suite *is_greater_suite6(void);
Suite *is_greater_suite7(void);
Suite *is_greater_suite8(void);
Suite *is_greater_suite9(void);
Suite *is_greater_suite10(void);
Suite *is_greater_suite11(void);
Suite *is_greater_suite12(void);
Suite *is_greater_suite13(void);
Suite *is_greater_suite14(void);
Suite *is_greater_suite15(void);
Suite *is_greater_suite16(void);
Suite *is_greater_suite3(void);
Suite *is_greater_suite3(void);
void test_is_greater(s21_decimal decimal1, s21_decimal decimal2, int check);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // S21_TESTS_H
