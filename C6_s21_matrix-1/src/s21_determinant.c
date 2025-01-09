#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (s21_NO_CORRECT_MATRIX(A) || result == NULL) {
    return NO_CORRECT;
  } else if (A->columns != A->rows) {
    flag = NO_ARITHMETIC;
  } else {
    matrix_t temp;
    s21_create_matrix(A->columns, A->columns, &temp);
    s21_copy_matrix(A, &temp);
    double det = 1.0;
    for (int i = 0; i < A->columns; i++) {
      int max_row = i;
      for (int k = i + 1; k < A->columns; k++) {
        if (fabs(temp.matrix[k][i]) > fabs(temp.matrix[max_row][i])) {
          max_row = k;
        }
      }
      if (fabs(temp.matrix[max_row][i]) < 1e-9) {
        det = 0;
        break;
      }
      if (i != max_row) {
        for (int j = 0; j < A->columns; j++) {
          double tmp = temp.matrix[i][j];
          temp.matrix[i][j] = temp.matrix[max_row][j];
          temp.matrix[max_row][j] = tmp;
        }
        det = -det;
      }
      det *= temp.matrix[i][i];
      for (int k = i + 1; k < A->columns; k++) {
        double c = temp.matrix[k][i] / temp.matrix[i][i];
        for (int j = i; j < A->columns; j++) {
          temp.matrix[k][j] -= c * temp.matrix[i][j];
        }
      }
    }
    *result = det;
    s21_remove_matrix(&temp);
  }
  return flag;
}