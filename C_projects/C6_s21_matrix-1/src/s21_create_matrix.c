#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1 || result == NULL) {
    if (result != NULL) {
      result->rows = rows;
      result->columns = columns;
    }
    return NO_CORRECT;
  }
  int flag = OK;
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));
  }

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0.0;
    }
  }
  return flag;
}
