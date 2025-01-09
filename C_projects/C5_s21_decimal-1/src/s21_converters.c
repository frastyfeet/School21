#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) return 1;

  s21_clear_decimal(dst);

  if (src < 0) {
    s21_set_sign(dst, 1);
    src = -src;
  } else {
    s21_set_sign(dst, 0);
  }
  dst->bits[0] = src;

  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (!dst || incorrect_dec(src)) return 1;
  int flag = 0;

  *dst = src.bits[0];

  if (s21_get_sign(src) && (!s21_checkbit(src.bits[0], 31))) {
    *dst = -*dst;
  } else
    flag = 1;

  *dst = *dst / (int)pow(10, s21_get_scale(src));

  return flag;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 1;
  unsigned int bits = *(unsigned int *)&src;
  if (dst && !isinf(src) && !isnan(src)) {
    s21_clear_decimal(dst);
    int scale = 0;
    int sign = (src <= 0.0 && (bits >> 31) & 1) ? 1 : 0;
    if (sign) {
      src = -src;
    }

    if (s21_is_zero_float(src)) {
      s21_handle_zero_float(sign, dst);
      flag = 0;
    } else if (s21_is_overflow_float(src)) {
      flag = 1;
    } else {
      s21_normalize_float(&src, &scale);
      if (scale <= 28) {
        s21_handle_normalized_float(src, &scale, dst);
        s21_set_scale(dst, scale);
        s21_set_sign(dst, sign);
        flag = 0;
      }
    }
  }
  return flag;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 1;
  if (dst && !incorrect_dec(src)) {
    if (s21_get_sign(src)) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    int expanent = s21_get_scale(src);
    double temp_float = 0.0;
    for (int i = 0; i < 96; i++) {
      if ((src.bits[i / 32] & (1 << i % 32)) != 0) {
        temp_float += pow(2, i);
      }
    }
    if (expanent > 0) {
      for (int i = 0; i < expanent; i++) {
        temp_float = temp_float / 10.0;
      }
    }
    if (s21_get_sign(src)) {
      temp_float = -temp_float;
    }
    *dst = (float)temp_float;
    flag = 0;
  }
  return flag;
}