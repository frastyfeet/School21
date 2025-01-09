#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if ((s21_NO_CORRECT_MATRIX(A) || s21_NO_CORRECT_MATRIX(B)) ||
      (A->columns != B->columns) || (A->rows != B->rows)) {
    flag = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round(A->matrix[i][j] * 10000000) !=
            round(B->matrix[i][j] * 10000000))
          flag = FAILURE;
      }
    }
  }
  return flag;
}