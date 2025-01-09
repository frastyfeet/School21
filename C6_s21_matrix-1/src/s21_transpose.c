#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_NO_CORRECT_MATRIX(A) || result == NULL) {
    return NO_CORRECT;
  } else if (s21_create_matrix(A->columns, A->rows, result) == 0) {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return flag;
}