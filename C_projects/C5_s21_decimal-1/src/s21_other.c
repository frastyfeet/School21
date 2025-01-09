#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal* result) {
  int flag = 0;
  if (!result || incorrect_dec(value)) return 1;

  s21_clear_decimal(result);
  *result = value;
  result->bits[3] = 0;
  s21_set_sign(result, !s21_get_sign(value));
  s21_set_scale(result, s21_get_scale(value));

  return flag;
}

int s21_truncate(s21_decimal number, s21_decimal* result) {
  if (!result || incorrect_dec(number)) return 1;

  s21_clear_decimal(result);
  int scale = s21_get_scale(number);

  if (scale != 0) {
    for (int i = 0; i < scale; i++) {
      s21_div_10_dec(&number);
    }
  }

  *result = number;
  result->bits[3] = 0;
  s21_set_sign(result, s21_get_sign(number));

  return 0;
}

int s21_floor(s21_decimal value, s21_decimal* result) {
  if (!result || incorrect_dec(value)) return 1;

  int flag = 0;
  s21_decimal fraction;
  s21_clear_decimal(result);

  s21_truncate(value, result);
  s21_sub(value, *result, &fraction);

  if (s21_get_sign(value) && s21_get_scale(value) <= 28 &&
      !s21_is_equal(value, *result) && !is_zero_dec(fraction)) {
    flag = s21_sub(*result, (s21_decimal){{1, 0, 0, 0}}, result);
  }

  return flag;
}

int s21_round(s21_decimal number, s21_decimal* result) {
  if (!result || incorrect_dec(number)) return 1;

  s21_decimal temp = *result;
  s21_clear_decimal(result);
  s21_decimal fraction = {{0}};

  s21_truncate(number, result);
  s21_sub(number, *result, &fraction);
  fraction.bits[3] = 0;
  s21_set_scale(&fraction, s21_get_scale(number));

  s21_decimal half_unit = {{0x5, 0, 0, 0}};

  int scale = s21_get_scale(fraction);
  for (int i = scale; i > 1; i--) {
    mul_10_dec(1, 0, &half_unit);
  }

  s21_set_scale(&half_unit, scale);

  s21_banking(fraction, half_unit, result);

  if (s21_is_equal(number, temp)) {
    *result = temp;
    s21_set_sign(result, s21_get_sign(number));
  }

  return 0;
}
