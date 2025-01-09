#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = S21_ARITHMETIC_ERROR;
  if (result && !incorrect_dec(value_1) && !incorrect_dec(value_2)) {
    s21_clear_decimal(result);
    s21_big_decimal num1 = {{0}}, num2 = {{0}}, res = {{0}};
    int sign1 = s21_get_sign(value_1), sign2 = s21_get_sign(value_2);
    int sign = (sign1 == sign2);
    to_big_decimal(&value_1, &num1);
    to_big_decimal(&value_2, &num2);
    int scale = s21_normalization(&num1, &num2, &value_1, &value_2);
    uint64_t carry = 0;

    if (sign) {
      s21_add_big_decimale(num1, num2, &res);
    } else {
      s21_sub_big_decimale(num1, num2, &res, s21_is_big_greater(num2, num1),
                           sign1, sign2);
    }

    s21_post_normalization(&res, &scale, &carry);

    if (res.bits[3] == 0) {
      convert_to_decimal(&res, result);
      s21_set_sign(
          result,
          (sign ? sign1 : (s21_is_big_greater(num1, num2) ? sign1 : sign2)));
      s21_set_scale(result, scale);

      if (carry >= 5) {
        s21_decimal dec1 = {{1, 0, 0, 0}};
        s21_set_scale(&dec1, scale);
        s21_set_sign(&dec1, s21_get_sign(*result));
        s21_add(*result, dec1, result);
      }
      flag = S21_ARITHMETIC_OK;
    } else {
      flag = sign1 ? S21_ARITHMETIC_LESS : S21_ARITHMETIC_MORE;
    }
  }
  return flag;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = S21_ARITHMETIC_ERROR;
  if (result && !incorrect_dec(value_1) && !incorrect_dec(value_2)) {
    s21_clear_decimal(result);
    s21_big_decimal num1 = {{0}}, num2 = {{0}}, res = {{0}};
    int sign1 = s21_get_sign(value_1), sign2 = s21_get_sign(value_2);
    int same_sign = (sign1 == sign2);
    to_big_decimal(&value_1, &num1);
    to_big_decimal(&value_2, &num2);
    int scale = s21_normalization(&num1, &num2, &value_1, &value_2);
    uint64_t carry = 0;

    if (same_sign) {
      int less_decimal = s21_is_big_greater(num2, num1);
      s21_sub_big_decimale(num1, num2, &res, less_decimal, sign1, sign2);
      s21_set_sign(result, less_decimal ? !sign1 : sign1);
    } else {
      s21_add_big_decimale(num1, num2, &res);
      s21_set_sign(result, sign1);
    }

    s21_post_normalization(&res, &scale, &carry);

    if (res.bits[3] == 0) {
      convert_to_decimal(&res, result);
      s21_set_scale(result, scale);

      if (carry >= 5) {
        s21_decimal dec1 = {{1, 0, 0, 0}};
        s21_set_scale(&dec1, scale);
        s21_set_sign(&dec1, s21_get_sign(*result));
        s21_add(*result, dec1, result);
      }
      flag = S21_ARITHMETIC_OK;
    } else {
      flag = sign1 ? S21_ARITHMETIC_LESS : S21_ARITHMETIC_MORE;
    }
  }
  return flag;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = S21_ARITHMETIC_ERROR;

  if (result && !incorrect_dec(value_1) && !incorrect_dec(value_2)) {
    s21_clear_decimal(result);
    s21_big_decimal num1 = {{0}}, num2 = {{0}}, res = {{0}};
    to_big_decimal(&value_1, &num1);
    to_big_decimal(&value_2, &num2);

    int sign = s21_get_sign(value_1) != s21_get_sign(value_2);
    int scale = s21_get_scale(value_1) + s21_get_scale(value_2);
    uint64_t carry = 0;

    s21_mul_big_decimale(num1, num2, &res);
    s21_post_normalization(&res, &scale, &carry);

    if (res.bits[3] == 0) {
      convert_to_decimal(&res, result);
      s21_set_sign(result, sign);
      s21_set_scale(result, scale);

      if (carry >= 5) {
        s21_decimal dec1 = {{1, 0, 0, 0}};
        s21_set_scale(&dec1, s21_get_scale(*result));
        s21_set_sign(&dec1, s21_get_sign(*result));
        s21_add(*result, dec1, result);
        s21_round(*result, result);
      }

      flag = S21_ARITHMETIC_OK;
    } else {
      flag = sign ? S21_ARITHMETIC_LESS : S21_ARITHMETIC_MORE;
    }
  }

  return flag;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result || incorrect_dec(value_1) || incorrect_dec(value_2)) {
    return S21_ARITHMETIC_ERROR;
  }
  int flag = 0;

  if (is_zero_dec(value_2)) return S21_ARITHMETIC_DIV_ZERO;

  int sign = (s21_get_sign(value_1) == s21_get_sign(value_2)) ? 0 : 1;
  s21_clear_decimal(result);

  s21_big_decimal num1 = {{0}}, num2 = {{0}}, quotient = {{0}},
                  remainder = {{0}}, res = {{0}};
  to_big_decimal(&value_1, &num1);
  to_big_decimal(&value_2, &num2);

  int result_scale = s21_get_scale(value_1) - s21_get_scale(value_2);
  s21_div_quotient(num1, num2, &quotient, &remainder);

  if (!is_zero_big_dec(&remainder)) {
    s21_div_remainder(&quotient, &remainder, num2, &res, &result_scale);
  } else {
    res = quotient;
  }

  uint64_t carry = 0;
  s21_post_normalization(&res, &result_scale, &carry);
  if (res.bits[3] == 0) {
    convert_to_decimal(&res, result);
    s21_set_scale(result, result_scale);
    s21_set_sign(result, sign);

    if (carry >= 5) {
      s21_decimal dec1 = {{1, 0, 0, 0}};
      s21_set_scale(&dec1, s21_get_scale(*result));
      s21_set_sign(&dec1, s21_get_sign(*result));
      s21_add(*result, dec1, result);
    }
    flag = S21_ARITHMETIC_OK;
  } else if (!sign) {
    flag = S21_ARITHMETIC_MORE;
  } else if (sign) {
    flag = S21_ARITHMETIC_LESS;
  }
  return flag;
}

void s21_mul_big_decimale(s21_big_decimal number1, s21_big_decimal number2,
                          s21_big_decimal *result) {
  s21_big_decimal temp_result = {{0}}, temp_number2 = number2;
  for (int i = 0; i < 96; ++i) {
    if (s21_checkbit(number1.bits[i / 32], (i % 32))) {
      s21_add_big_decimale(temp_result, temp_number2, &temp_result);
    }
    s21_left_shift_decimal(&temp_number2, 1);
  }

  *result = temp_result;
}

void s21_sub_big_decimale(s21_big_decimal number1, s21_big_decimal number2,
                          s21_big_decimal *result, int less_decimal, int sign1,
                          int sign2) {
  int carry = 0;
  s21_big_decimal tmp = {{0}};

  for (int i = 0; i < 8; i++) {
    int64_t diff;
    if (less_decimal) {
      diff = (int64_t)number2.bits[i] - carry - (int64_t)number1.bits[i];
    } else {
      diff = (int64_t)number1.bits[i] - carry - (int64_t)number2.bits[i];
    }

    if (diff < 0) {
      diff += ((uint64_t)1 << 32);
      carry = 1;
    } else {
      carry = 0;
    }

    tmp.bits[i] = (uint32_t)diff;
  }

  *result = tmp;

  if ((less_decimal && sign1 == 0 && sign2 == 0) ||
      (!less_decimal && sign1 == 1 && sign2 == 0) ||
      (!less_decimal && sign1 == 1 && sign2 == 1) ||
      (less_decimal && sign1 == 0 && sign2 == 1)) {
    result->bits[7] = 1;
  }
}

void s21_add_big_decimale(s21_big_decimal number1, s21_big_decimal number2,
                          s21_big_decimal *result) {
  uint64_t carry = 0;
  for (int i = 0; i < 8; i++) {
    uint64_t sum = (uint64_t)number1.bits[i] + number2.bits[i] + carry;
    carry = sum >> 32;
    result->bits[i] = (uint32_t)(sum & 0xFFFFFFFF);
  }
}

void s21_div_quotient(s21_big_decimal number1, s21_big_decimal number2,
                      s21_big_decimal *quotient, s21_big_decimal *remainder) {
  s21_big_decimal temp_num1 = number1;
  s21_big_decimal temp_num2 = number2;
  s21_big_decimal zero = {{0}};
  int shift_count = 0;

  while (s21_is_less_or_equal_big(temp_num2, temp_num1)) {
    s21_left_shift_decimal(&temp_num2, 1);
    shift_count++;
  }
  s21_right_shift_decimal(&temp_num2, 1);
  shift_count--;

  *remainder = temp_num1;
  *quotient = zero;
  while (shift_count >= 0) {
    if (s21_is_less_or_equal_big(temp_num2, *remainder)) {
      int shift_count_i = shift_count;
      s21_big_decimal shift_number = {{1}};
      s21_sub_big_decimale(*remainder, temp_num2, remainder, 0, 0, 0);
      while (shift_count_i) {
        s21_left_shift_decimal(&shift_number, 1);
        shift_count_i--;
      }
      s21_add_big_decimale(*quotient, shift_number, quotient);
    }
    s21_right_shift_decimal(&temp_num2, 1);
    shift_count--;
  }
}

void s21_div_remainder(s21_big_decimal *quotient, s21_big_decimal *remainder,
                       s21_big_decimal num2, s21_big_decimal *result,
                       int *scale) {
  s21_big_decimal temp_num = {{0}}, remainder_temp = {{0}};
  int counter = 0;
  unsigned int data[1000000] = {0};
  while (!is_zero_big_dec(remainder) && *scale < 29) {
    mul_10(1, 0, remainder);
    mul_10(1, 0, quotient);

    s21_div_quotient(*remainder, num2, &temp_num, remainder);
    data[counter] = temp_num.bits[0];
    *scale += 1;
    counter++;
  }
  for (int i = 0; i < counter; i++) {
    s21_big_decimal data_num = {{data[i]}};
    mul_10(1, 0, &remainder_temp);
    s21_add_big_decimale(remainder_temp, data_num, &remainder_temp);
  }

  s21_add_big_decimale(*quotient, remainder_temp, result);
}
