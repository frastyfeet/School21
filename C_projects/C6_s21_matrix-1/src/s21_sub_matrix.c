#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_NO_CORRECT_MATRIX(A) || s21_NO_CORRECT_MATRIX(B)) {
    return NO_CORRECT;
  }
  int flag = OK;
  if ((A->columns != B->columns) || (A->rows != B->rows))
    flag = NO_ARITHMETIC;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return flag;
}