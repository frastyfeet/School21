#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_NO_CORRECT_MATRIX(A) || result == NULL) {
    return NO_CORRECT;
  }
  int flag = OK;
  if (A->columns != A->rows) {
    flag = NO_ARITHMETIC;
  } else {
    matrix_t temp = {0};
    matrix_t temp_t = {0};
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0.0) {
      s21_calc_complements(A, &temp);
      s21_transpose(&temp, &temp_t);
      s21_copy_matrix(result, &temp_t);
      s21_mult_number(&temp_t, 1 / det, result);
      s21_remove_matrix(&temp_t);
      s21_remove_matrix(&temp);
    } else {
      s21_remove_matrix(&temp_t);
      s21_remove_matrix(&temp);
      flag = NO_ARITHMETIC;
    }
  }
  return flag;
}