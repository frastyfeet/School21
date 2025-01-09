#include <check.h>
#include <errno.h>

#include "s21_matrix.h"

START_TEST(test_s21_create_matrix_1) {
  matrix_t A = {0};
  int res = s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(A.rows, 2);
  ck_assert_int_eq(A.columns, 3);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  matrix_t A = {0};
  int res = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(A.rows, 3);
  ck_assert_int_eq(A.columns, 3);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  matrix_t A = {0};
  int res = s21_create_matrix(0, 3, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  matrix_t A = {0};
  int res = s21_create_matrix(3, -3, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_create_matrix_5) {
  int res = s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_s21_eq_matrix_1) {
  double count = 1.0;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  double count = 1.0;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 1, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  double count = 1.0;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  B.matrix[2][2] += 0.0000009;
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count + 1.0;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(-1, 1, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
      count = count + 1.0;
    }
  }

  int res = s21_sum_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_sub_matrix_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
      count = count + 1.0;
    }
  }

  int res = s21_sub_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_mult_number_1) {
  double number = 2.0;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  double number = 0.5;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  double number = -1.0;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  double number = 0.0;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(4, 1, &A);
  s21_create_matrix(4, 1, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_5) {
  double number = 3.0;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_6) {
  double number = 2.5;
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = A.matrix[i][j] * number;
      count = count + 1.0;
    }
  }

  int res = s21_mult_number(&A, number, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_number_7) {
  double number = 2.0;
  matrix_t A = {0};
  matrix_t C = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &C);

  int res = s21_mult_number(&A, number, &C);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

// mult_matrix
START_TEST(test_s21_mult_matrix_1) {
  double count = 1.0;
  double count2 = 3.0;
  matrix_t A;
  matrix_t B;
  matrix_t C = {0};
  matrix_t D = {0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(1, 1, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[j][i] = count2;
      count = count + 1.0;
      count2 = count2 - 1.0;
    }
  }
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      for (int k = 0; k < B.rows; k++) {
        C.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
      }
    }
  }

  int res = s21_mult_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A, B, C;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(4, 1, &B);
  s21_create_matrix(1, 1, &C);

  int res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t A, B, C, D;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;

  C.matrix[0][0] = 1 * 5 + 2 * 7;
  C.matrix[0][1] = 1 * 6 + 2 * 8;
  C.matrix[1][0] = 3 * 5 + 4 * 7;
  C.matrix[1][1] = 3 * 6 + 4 * 8;

  int res = s21_mult_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;

  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 9;
  B.matrix[1][0] = 10;
  B.matrix[1][1] = 11;
  B.matrix[1][2] = 12;

  C.matrix[0][0] = 1 * 7 + 2 * 10;
  C.matrix[0][1] = 1 * 8 + 2 * 11;
  C.matrix[0][2] = 1 * 9 + 2 * 12;
  C.matrix[1][0] = 3 * 7 + 4 * 10;
  C.matrix[1][1] = 3 * 8 + 4 * 11;
  C.matrix[1][2] = 3 * 9 + 4 * 12;
  C.matrix[2][0] = 5 * 7 + 6 * 10;
  C.matrix[2][1] = 5 * 8 + 6 * 11;
  C.matrix[2][2] = 5 * 9 + 6 * 12;

  int res = s21_mult_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);

  int res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_mult_matrix_6) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 10;
  B.matrix[0][1] = 11;
  B.matrix[0][2] = 12;
  B.matrix[1][0] = 13;
  B.matrix[1][1] = 14;
  B.matrix[1][2] = 15;
  B.matrix[2][0] = 16;
  B.matrix[2][1] = 17;
  B.matrix[2][2] = 18;

  C.matrix[0][0] = 1 * 10 + 2 * 13 + 3 * 16;
  C.matrix[0][1] = 1 * 11 + 2 * 14 + 3 * 17;
  C.matrix[0][2] = 1 * 12 + 2 * 15 + 3 * 18;
  C.matrix[1][0] = 4 * 10 + 5 * 13 + 6 * 16;
  C.matrix[1][1] = 4 * 11 + 5 * 14 + 6 * 17;
  C.matrix[1][2] = 4 * 12 + 5 * 15 + 6 * 18;
  C.matrix[2][0] = 7 * 10 + 8 * 13 + 9 * 16;
  C.matrix[2][1] = 7 * 11 + 8 * 14 + 9 * 17;
  C.matrix[2][2] = 7 * 12 + 8 * 15 + 9 * 18;

  int res = s21_mult_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(test_s21_mult_matrix_7) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_s21_transpose_1) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[j][i] = count;
      count = count + 1.0;
    }
  }

  int res = s21_transpose(&A, &C);
  int res_eq = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t A = {0};
  matrix_t C = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(3, 3, &C);

  int res = s21_transpose(&A, &C);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

// calc_complements
START_TEST(test_s21_calc_complements_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], 0);
  ck_assert_int_eq(B.matrix[0][1], 10);
  ck_assert_int_eq(B.matrix[0][2], -20);
  ck_assert_int_eq(B.matrix[1][0], 4);
  ck_assert_int_eq(B.matrix[1][1], -14);
  ck_assert_int_eq(B.matrix[1][2], 8);
  ck_assert_int_eq(B.matrix[2][0], -8);
  ck_assert_int_eq(B.matrix[2][1], -2);
  ck_assert_int_eq(B.matrix[2][2], 4);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;

  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(B.matrix[0][0], -12);
  ck_assert_int_eq(B.matrix[0][1], 20);
  ck_assert_int_eq(B.matrix[0][2], -2);
  ck_assert_int_eq(B.matrix[1][0], 0);
  ck_assert_int_eq(B.matrix[1][1], 0);
  ck_assert_int_eq(B.matrix[1][2], 0);
  ck_assert_int_eq(B.matrix[2][0], 12);
  ck_assert_int_eq(B.matrix[2][1], -20);
  ck_assert_int_eq(B.matrix[2][2], 2);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);

  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_complements_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(0, 0, &A);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_s21_determinant_1) {
  double count = 1.0;
  double determinant = 0.0;
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      count = count + 1.0;
    }
  }

  int res = s21_determinant(&A, &determinant);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(determinant, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  double determinant = 0.0;
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 13;
  A.matrix[0][3] = 7;

  A.matrix[1][0] = 5;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 23;
  A.matrix[1][3] = 11;

  A.matrix[2][0] = 13;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 9;
  A.matrix[2][3] = 8;

  A.matrix[3][0] = 20;
  A.matrix[3][1] = 12;
  A.matrix[3][2] = 4;
  A.matrix[3][3] = 7;

  int res = s21_determinant(&A, &determinant);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(determinant, 596, 6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  double determinant = 0.0;
  matrix_t A;
  s21_create_matrix(3, 1, &A);

  int res = s21_determinant(&A, &determinant);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  double determinant = 0.0;
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 27;

  int res = s21_determinant(&A, &determinant);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(determinant, 27);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  double determinant = 0.0;
  matrix_t A;
  s21_create_matrix(0, 0, &A);
  int res = s21_determinant(&A, &determinant);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

// inverse_matrix
START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  ck_assert_double_eq_tol(B.matrix[0][0], 1, 6);
  ck_assert_double_eq_tol(B.matrix[0][1], -1, 6);
  ck_assert_double_eq_tol(B.matrix[0][2], 1, 6);
  ck_assert_double_eq_tol(B.matrix[1][0], -38, 6);
  ck_assert_double_eq_tol(B.matrix[1][1], 41, 6);
  ck_assert_double_eq_tol(B.matrix[1][2], -34, 6);
  ck_assert_double_eq_tol(B.matrix[2][0], 27, 6);
  ck_assert_double_eq_tol(B.matrix[2][1], -29, 6);
  ck_assert_double_eq_tol(B.matrix[2][2], 24, 6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 8;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 2, &A);

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(0, 0, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}

Suite *create_suite_create() {
  Suite *suite = suite_create("\n CREATE");
  TCase *tcase = tcase_create("\n CREATE");

  tcase_add_test(tcase, test_s21_create_matrix_1);
  tcase_add_test(tcase, test_s21_create_matrix_2);
  tcase_add_test(tcase, test_s21_create_matrix_3);
  tcase_add_test(tcase, test_s21_create_matrix_4);
  tcase_add_test(tcase, test_s21_create_matrix_5);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_equal() {
  Suite *suite = suite_create("EQUAL");
  TCase *tcase = tcase_create("EQUAL");

  tcase_add_test(tcase, test_s21_eq_matrix_1);
  tcase_add_test(tcase, test_s21_eq_matrix_2);
  tcase_add_test(tcase, test_s21_eq_matrix_3);
  tcase_add_test(tcase, test_s21_eq_matrix_4);
  tcase_add_test(tcase, test_s21_eq_matrix_5);
  tcase_add_test(tcase, test_s21_eq_matrix_6);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_sum() {
  Suite *suite = suite_create("SUM");
  TCase *tcase = tcase_create("SUM");

  tcase_add_test(tcase, test_s21_sum_matrix_1);
  tcase_add_test(tcase, test_s21_sum_matrix_2);
  tcase_add_test(tcase, test_s21_sum_matrix_3);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_sub() {
  Suite *suite = suite_create("SUB");
  TCase *tcase = tcase_create("SUB");

  tcase_add_test(tcase, test_s21_sub_matrix_1);
  tcase_add_test(tcase, test_s21_sub_matrix_2);
  tcase_add_test(tcase, test_s21_sub_matrix_3);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_multi_num() {
  Suite *suite = suite_create("MULTI_NUM");
  TCase *tcase = tcase_create("MULTI_NUM");

  tcase_add_test(tcase, test_s21_mult_number_1);
  tcase_add_test(tcase, test_s21_mult_number_2);
  tcase_add_test(tcase, test_s21_mult_number_3);
  tcase_add_test(tcase, test_s21_mult_number_4);
  tcase_add_test(tcase, test_s21_mult_number_5);
  tcase_add_test(tcase, test_s21_mult_number_6);
  tcase_add_test(tcase, test_s21_mult_number_7);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_transpose() {
  Suite *suite = suite_create("TRANSPOSE");
  TCase *tcase = tcase_create("TRANSPOSE");

  tcase_add_test(tcase, test_s21_transpose_1);
  tcase_add_test(tcase, test_s21_transpose_2);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_multi_mat() {
  Suite *suite = suite_create("MULTI_MAT");
  TCase *tcase = tcase_create("MULTI_MAT");

  tcase_add_test(tcase, test_s21_mult_matrix_1);
  tcase_add_test(tcase, test_s21_mult_matrix_2);
  tcase_add_test(tcase, test_s21_mult_matrix_3);
  tcase_add_test(tcase, test_s21_mult_matrix_4);
  tcase_add_test(tcase, test_s21_mult_matrix_5);
  tcase_add_test(tcase, test_s21_mult_matrix_6);
  tcase_add_test(tcase, test_s21_mult_matrix_7);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_determinant() {
  Suite *suite = suite_create("DETERMINANT");
  TCase *tcase = tcase_create("DETERMINANT");

  tcase_add_test(tcase, test_s21_determinant_1);
  tcase_add_test(tcase, test_s21_determinant_2);
  tcase_add_test(tcase, test_s21_determinant_4);
  tcase_add_test(tcase, test_s21_determinant_5);
  tcase_add_test(tcase, test_s21_determinant_6);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_complements() {
  Suite *suite = suite_create("COMPLEMENTS");
  TCase *tcase = tcase_create("COMPLEMENTS");

  tcase_add_test(tcase, test_s21_calc_complements_1);
  tcase_add_test(tcase, test_s21_calc_complements_2);
  tcase_add_test(tcase, test_s21_calc_complements_3);
  tcase_add_test(tcase, test_s21_calc_complements_4);

  suite_add_tcase(suite, tcase);
  return suite;
}

Suite *create_suite_inverse() {
  Suite *suite = suite_create("INVERSE");
  TCase *tcase = tcase_create("INVERSE");

  tcase_add_test(tcase, test_s21_inverse_matrix_1);
  tcase_add_test(tcase, test_s21_inverse_matrix_2);
  tcase_add_test(tcase, test_s21_inverse_matrix_3);
  tcase_add_test(tcase, test_s21_inverse_matrix_4);

  suite_add_tcase(suite, tcase);
  return suite;
}

int main(void) {
  int number_failed;
  SRunner *runner;

  runner = srunner_create(create_suite_create());
  srunner_add_suite(runner, create_suite_equal());
  srunner_add_suite(runner, create_suite_sum());
  srunner_add_suite(runner, create_suite_sub());
  srunner_add_suite(runner, create_suite_multi_num());
  srunner_add_suite(runner, create_suite_transpose());
  srunner_add_suite(runner, create_suite_multi_mat());
  srunner_add_suite(runner, create_suite_determinant());
  srunner_add_suite(runner, create_suite_complements());
  srunner_add_suite(runner, create_suite_inverse());

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}