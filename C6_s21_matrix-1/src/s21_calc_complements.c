#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_NO_CORRECT_MATRIX(A))
    flag = NO_CORRECT;
  else if (A->columns != A->rows)
    flag = NO_ARITHMETIC;
  else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double determinant = 0;
        s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
        s21_get_minor(A, &minor, i, j);
        s21_determinant(&minor, &determinant);
        result->matrix[i][j] = pow(-1, (i + j)) * determinant;
        s21_remove_matrix(&minor);
      }
    }
  }
  return flag;
}