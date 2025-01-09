#include "s21_decimal.h"

// void s21_print_binary(int num) {
//   for (int i = 31; i >= 0; i--) {
//     printf("%d", (num >> i) & 1);
//   }
//   printf("\n");
// }

// void s21_print_decimal(s21_decimal num) {
//   for (int i = 3; i >= 0; i--) {
//     s21_print_binary(num.bits[i]);
//   }
//   printf("\n");
// }
// void s21_print_big_decimal(s21_big_decimal num) {
//   for (int i = 7; i >= 0; i--) {
//     s21_print_binary(num.bits[i]);
//   }
//   printf("\n");
// }

// void s21_print_float_binary(float num) {
//   uint32_t int_repres;
//   memcpy(&int_repres, &num, sizeof(float));

//   for (int i = 31; i >= 0; i--) {
//     printf("%d", (int_repres >> i) & 1);
//   }
//   printf("\n");
// }

void s21_set_sign(s21_decimal *num, int sign) { num->bits[3] |= (sign << 31); }

void s21_set_scale(s21_decimal *num, int scale) { num->bits[3] |= scale << 16; }

int s21_checkbit(const int value, const int position) {
  return ((value & (1 << position)) != 0);
}

void s21_banking(s21_decimal fraction, s21_decimal half_unit,

                 s21_decimal *result) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  s21_set_scale(&dec1, s21_get_scale(*result));
  s21_set_sign(&dec1, s21_get_sign(*result));
  if (s21_is_greater(fraction, half_unit)) {
    s21_add(*result, dec1, result);
  }
  if (s21_is_equal(fraction, half_unit)) {
    int integral = 0;
    s21_from_decimal_to_int(*result, &integral);
    if (integral % 2 != 0) {
      s21_add(*result, dec1, result);
    }
  }
}

int s21_setbit(const int value, const int position) {
  return (value | (1 << position));
}

int incorrect_dec(s21_decimal value) {
  int flag = 0;
  for (int i = 0; i <= 15; i++) {
    if (s21_checkbit(value.bits[3], i)) {
      flag = 1;
    }
  }
  for (int i = 0; i <= 6; i++) {
    if (s21_checkbit(value.bits[3], (i + 24))) {
      flag = 1;
    }
  }
  if (s21_get_scale(value) > 28) flag = 1;

  return flag;
}

int s21_get_scale(s21_decimal num) {
  int scale = 0;
  for (int i = 0; i < 7; i++) {
    if (s21_checkbit(num.bits[3], (i + 16)) == 1) scale = s21_setbit(scale, i);
  }
  return scale;
}
int s21_get_sign(s21_decimal num) { return s21_checkbit(num.bits[3], 31); }

void s21_clear_decimal(s21_decimal *number) {
  number->bits[0] = number->bits[1] = number->bits[2] = number->bits[3] = 0;
}

void s21_right_shift_decimal(s21_big_decimal *num, int shift_value) {
  uint32_t carry = 0;
  for (int i = 7; i >= 0; i--) {
    uint32_t current = num->bits[i];
    num->bits[i] = (current >> shift_value) | carry;
    carry = current << (32 - shift_value);
  }
}

void s21_left_shift_decimal(s21_big_decimal *num, int shift_value) {
  unsigned mem = 0;
  for (int i = 0; i < 7; i++) {
    unsigned temp = num->bits[i];
    num->bits[i] = (temp << shift_value) | mem;
    mem = temp >> (32 - shift_value);
  }
}

void s21_left_shift_decimal_notbig(s21_decimal *num, int shift_value) {
  unsigned mem = 0;
  for (int i = 0; i < 3; i++) {
    unsigned temp = num->bits[i];
    num->bits[i] = (temp << shift_value) | mem;
    mem = temp >> (32 - shift_value);
  }
}

void mul_10(int big_scale, int small_scale, s21_big_decimal *num1) {
  for (int i = 0; i < big_scale - small_scale; i++) {
    s21_big_decimal number3 = *num1;
    s21_big_decimal number5 = *num1;
    s21_left_shift_decimal(&number5, 3);
    s21_left_shift_decimal(&number3, 1);
    s21_add_big_decimale(number5, number3, num1);
  }
}

void mul_10_dec(int big_scale, int small_scale, s21_decimal *num1) {
  for (int i = 0; i < big_scale - small_scale; i++) {
    s21_decimal number3 = *num1;
    s21_decimal number5 = *num1;
    s21_left_shift_decimal_notbig(&number5, 3);
    s21_left_shift_decimal_notbig(&number3, 1);
    s21_add(number5, number3, num1);
  }
}

int s21_normalization(s21_big_decimal *num1, s21_big_decimal *num2,
                      s21_decimal *number1, s21_decimal *number2) {
  int big_scale = s21_get_scale(*number1) > s21_get_scale(*number2)
                      ? s21_get_scale(*number1)
                      : s21_get_scale(*number2);
  int small_scale = s21_get_scale(*number1) < s21_get_scale(*number2)
                        ? s21_get_scale(*number1)
                        : s21_get_scale(*number2);
  if (s21_get_scale(*number1) < s21_get_scale(*number2)) {
    mul_10(big_scale, small_scale, num1);
  } else {
    mul_10(big_scale, small_scale, num2);
  }
  return big_scale;
}

// void s21_right_shift_decimal_notbig(s21_decimal *num, int shift_value) {
//   unsigned mem = 0;
//   for (int i = 0; i < 1; i++) {
//     unsigned temp = num->bits[i];
//     num->bits[i] = (temp >> shift_value) | mem;
//     mem = temp << (32 - shift_value);
//   }
// }

void to_big_decimal(s21_decimal *small, s21_big_decimal *big) {
  for (int i = 0; i != 3; i++) big->bits[i] = small->bits[i];
}

void s21_div_10(s21_big_decimal *result, uint64_t *carry) {
  *carry = 0;
  uint64_t temp;

  for (int i = 6; i >= 0; --i) {
    temp = ((uint64_t)result->bits[i] + (*carry << 32));
    result->bits[i] = temp / 10;
    *carry = temp % 10;
  }
}

void s21_div_10_dec(s21_decimal *result) {
  uint64_t carry = 0;
  uint64_t temp;

  for (int i = 2; i >= 0; --i) {
    temp = ((uint64_t)result->bits[i] + (carry << 32));
    result->bits[i] = temp / 10;
    carry = temp % 10;
  }
}

void s21_post_normalization(s21_big_decimal *res, int *scale, uint64_t *carry) {
  while (*scale > 0 && res->bits[3] != 0) {
    --*scale;
    s21_div_10(res, carry);
  }
}

void convert_to_decimal(s21_big_decimal *num1, s21_decimal *res) {
  for (int i = 0; i < 3; i++) {
    res->bits[i] = num1->bits[i];
  }

  s21_set_sign(res, num1->bits[7]);
}

int is_zero_dec(s21_decimal value) {
  for (int i = 2; i >= 0; i--) {
    if (value.bits[i] != 0) {
      return 0;
    }
  }

  return 1;
}

int s21_get_float_exp(float *val) {
  return (*((int *)val) & ~(1u << 31) >> 23) - 127;
}

int is_zero_big_dec(s21_big_decimal *value) {
  for (int i = 0; i < 4; ++i) {
    if (value->bits[i] != 0) {
      return 0;
    }
  }
  return 1;
}

int s21_get_bit(s21_big_decimal dst, int index) {
  int mask = 1u << (index % 32);
  return (dst.bits[index / 32] & mask) != 0;
}

void s21_set_decimal_bit(s21_decimal *dst, int position) {
  int index = position / 32;
  int bit_pos = position % 32;
  dst->bits[index] = s21_setbit(dst->bits[index], bit_pos);
}

int s21_is_zero_float(float src) { return src == 0.0; }

int s21_is_overflow_float(float src) { return src >= 7992817255e+28f; }

void s21_handle_zero_float(int sign, s21_decimal *dst) {
  if (!sign) {
    s21_set_sign(dst, 0);
  } else {
    s21_set_sign(dst, 1);
  }
}

void s21_normalize_float(float *src, int *scale) {
  for (; *src < 1000000; (*scale)++) {
    *src *= 10;
    if (*src >= 1.0 && *scale == 6) {
      (*scale)++;
      break;
    }
  }
  for (; *src > 9999999.9999999; (*scale)--) {
    *src /= 10;
  }
  *src = round(*src);
}

void s21_handle_normalized_float(float src, int *scale, s21_decimal *dst) {
  int int_part = (int)src;
  for (; int_part % 10 == 0; (*scale)--) {
    int_part /= 10;
  }
  memcpy(&dst->bits[0], &int_part, sizeof(int));
  if (*scale < 0) {
    for (; *scale < 0; (*scale)++) {
      mul_10_dec(1, 0, dst);
    }
  }
}
