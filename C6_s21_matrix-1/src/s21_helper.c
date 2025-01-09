#include "s21_matrix.h"

int s21_NO_CORRECT_MATRIX(matrix_t *A) {
  int flag = FAILURE;
  if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL) {
    flag = SUCCESS;
  }
  return flag;
}
void s21_get_minor(matrix_t *src, matrix_t *dest, int row, int col) {
  int minor_row = 0, minor_col = 0;
  for (int i = 0; i < src->rows; i++) {
    if (i == row) continue;
    minor_col = 0;
    for (int j = 0; j < src->columns; j++) {
      if (j == col) continue;
      dest->matrix[minor_row][minor_col] = src->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
}
void s21_copy_matrix(matrix_t *src, matrix_t *dest) {
  for (int i = 0; i < src->rows; i++) {
    for (int j = 0; j < src->columns; j++) {
      dest->matrix[i][j] = src->matrix[i][j];
    }
  }
}