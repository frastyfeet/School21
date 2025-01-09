#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#define S21_ARITHMETIC_OK 0
#define S21_ARITHMETIC_MORE 1
#define S21_ARITHMETIC_LESS 2
#define S21_ARITHMETIC_DIV_ZERO 3
#define S21_ARITHMETIC_ERROR 4

#define S21_POSSITVE 0
#define S21_NEGATIVE 1

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

typedef struct {
  uint32_t int_part;
  float float_part;
} s21_float_bits;

// Arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);
int s21_mul(s21_decimal number_1, s21_decimal number_2, s21_decimal *result);

// Convertors
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

// Other functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal number, s21_decimal *result);
int s21_truncate(s21_decimal number, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Comparison
int s21_is_less_or_equal(s21_decimal number_1, s21_decimal number_2);
int s21_is_greater_or_equal(s21_decimal number_1, s21_decimal number_2);
int s21_is_greater(s21_decimal number_1, s21_decimal number_2);
int s21_is_equal(s21_decimal number_1, s21_decimal number_2);

int s21_is_big_greater(s21_big_decimal number_1, s21_big_decimal number_2);

// Big decimal Arithmetic
void s21_sub_big_decimale(s21_big_decimal number1, s21_big_decimal number2,
                          s21_big_decimal *result, int less_decimal, int sign1,
                          int sign2);
void s21_add_big_decimale(s21_big_decimal number1, s21_big_decimal number2,
                          s21_big_decimal *result);
void s21_mul_big_decimale(s21_big_decimal number1, s21_big_decimal number2,
                          s21_big_decimal *result);

void s21_banking(s21_decimal fraction, s21_decimal half_unit,
                 s21_decimal *result);

int s21_checkbit(const int value, const int position);
int s21_setbit(const int value, const int position);
int s21_get_float_exp(float *val);
int s21_get_scale(s21_decimal num);
int s21_get_sign(s21_decimal num);
void s21_set_sign(s21_decimal *num, int sign);
void s21_set_scale(s21_decimal *num, int scale);
void s21_clear_decimal(s21_decimal *number);
int is_zero_dec(s21_decimal value);
int incorrect_dec(s21_decimal value);
void convert_to_decimal(s21_big_decimal *num1, s21_decimal *res);
void to_big_decimal(s21_decimal *small, s21_big_decimal *big);

void s21_print_binary(int num);
void s21_print_decimal(s21_decimal num);
void s21_print_big_decimal(s21_big_decimal num);
void s21_print_float_binary(float num);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

void s21_left_shift_decimal(s21_big_decimal *num, int shift_value);
void s21_left_shift_decimal_notbig(s21_decimal *num, int shift_value);
void s21_div_10_dec(s21_decimal *result);
void s21_right_shift_decimal(s21_big_decimal *num, int shift_value);
void s21_right_shift_decimal_notbig(s21_decimal *num, int shift_value);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void mul_10(int big_scale, int small_scale, s21_big_decimal *num1);
void mul_10_dec(int big_scale, int small_scale, s21_decimal *num1);
void s21_div_10(s21_big_decimal *result, uint64_t *carry);

void s21_post_normalization(s21_big_decimal *res, int *scale, uint64_t *carry);
int s21_normalization(s21_big_decimal *num1, s21_big_decimal *num2,
                      s21_decimal *number1, s21_decimal *number2);
int s21_is_less(s21_decimal number_1, s21_decimal number_2);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_div_quotient(s21_big_decimal number1, s21_big_decimal number2,
                      s21_big_decimal *quotient, s21_big_decimal *remainder);
void s21_div_remainder(s21_big_decimal *quotient, s21_big_decimal *remainder,
                       s21_big_decimal num2, s21_big_decimal *result,
                       int *scale);

int is_zero_big_dec(s21_big_decimal *value);
int s21_is_less_or_equal_big(s21_big_decimal number_1,
                             s21_big_decimal number_2);

int s21_is_not_equal(s21_decimal number_1, s21_decimal number_2);
int s21_is_less(s21_decimal number_1, s21_decimal number_2);

int s21_get_bit(s21_big_decimal dst, int index);
int s21_comparison(s21_decimal value_1, s21_decimal value_2);

void s21_set_decimal_bit(s21_decimal *dst, int position);

int s21_is_zero_float(float src);
int s21_is_overflow_float(float src);
void s21_handle_zero_float(int sign, s21_decimal *dst);
void s21_normalize_float(float *src, int *scale);
void s21_handle_normalized_float(float src, int *scale, s21_decimal *dst);

#endif
