#include "s21_decimal.h"

int s21_comparison(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_value_1 = {{0}};
  s21_big_decimal big_value_2 = {{0}};
  to_big_decimal(&value_1, &big_value_1);
  to_big_decimal(&value_2, &big_value_2);
  s21_normalization(&big_value_1, &big_value_2, &value_1, &value_2);

  int res = 0;
  int flag_stop = 0;
  unsigned int sign_value_1 = s21_get_sign(value_1);
  unsigned int sign_value_2 = s21_get_sign(value_2);

  if (is_zero_dec(value_1) && is_zero_dec(value_2)) {
    res = 0;
  } else if (sign_value_1 && !sign_value_2) {
    res = -1;
  } else if (!sign_value_1 && sign_value_2) {
    res = 1;
  } else {
    for (int i = 223; i >= 0 && !flag_stop; i--) {
      int bit_value_1 = s21_get_bit(big_value_1, i);
      int bit_value_2 = s21_get_bit(big_value_2, i);
      if (bit_value_1 != bit_value_2) {
        flag_stop = 1;
        res = (bit_value_1 > bit_value_2) ? 1 : -1;
      }
    }
    if (sign_value_1 && sign_value_2 && flag_stop) {
      res = -res;
    }
  }
  return res;
}

int s21_is_less(s21_decimal number_1, s21_decimal number_2) {
  return s21_comparison(number_1, number_2) == -1;
}

int s21_is_less_or_equal(s21_decimal number_1, s21_decimal number_2) {
  return s21_comparison(number_1, number_2) <= 0;
}

int s21_is_greater(s21_decimal number_1, s21_decimal number_2) {
  return s21_comparison(number_1, number_2) == 1;
}

int s21_is_greater_or_equal(s21_decimal number_1, s21_decimal number_2) {
  return s21_comparison(number_1, number_2) >= 0;
}

int s21_is_equal(s21_decimal number_1, s21_decimal number_2) {
  return s21_comparison(number_1, number_2) == 0;
}

int s21_is_not_equal(s21_decimal number_1, s21_decimal number_2) {
  return s21_comparison(number_1, number_2) != 0;
}

// big_decimal

int s21_is_big_greater(s21_big_decimal number_1, s21_big_decimal number_2) {
  int flag = 0;
  for (int i = 7; i >= 0; i--) {
    if (number_1.bits[i] > number_2.bits[i]) {
      flag = 1;
      break;
    } else if (number_1.bits[i] < number_2.bits[i]) {
      flag = 0;
      break;
    }
  }

  return flag;
}

int s21_is_less_or_equal_big(s21_big_decimal number_1,
                             s21_big_decimal number_2) {
  for (int i = 5; i >= 0; i--) {
    if (number_1.bits[i] < number_2.bits[i]) return 1;
    if (number_1.bits[i] > number_2.bits[i]) return 0;
  }
  return 1;
}