#include "s21_matrix_oop.h"

void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[columns_]();
  }
}

void S21Matrix::FreeMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix() : rows_(3), columns_(3) { AllocateMatrix(); }

S21Matrix::S21Matrix(int rows, int columns) : rows_(rows), columns_(columns) {
  if (rows <= 0 || columns <= 0) {
    throw std::invalid_argument("Matrix dimensions must be positive");
  }
  AllocateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), columns_(other.columns_) {
  AllocateMatrix();
  CopyData(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), columns_(other.columns_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.columns_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { FreeMatrix(); }

void S21Matrix::CopyData(const S21Matrix& other) {
  for (int i = 0; i < rows_; ++i) {
    std::copy(other.matrix_[i], other.matrix_[i] + columns_, matrix_[i]);
  }
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  ValidateSameSize(other);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  ValidateSameSize(other);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (columns_ != other.rows_) {
    throw std::invalid_argument(
        "Matrix sizes are incompatible for multiplication");
  }

  S21Matrix tmp(rows_, other.columns_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.columns_; ++j) {
      tmp.matrix_[i][j] = MultiplyRowByColumn(*this, other, i, j);
    }
  }
  *this = std::move(tmp);
}

double S21Matrix::MultiplyRowByColumn(const S21Matrix& m1, const S21Matrix& m2,
                                      int row, int col) const {
  double result = 0.0;
  for (int k = 0; k < m1.columns_; ++k) {
    result += m1.matrix_[row][k] * m2.matrix_[k][col];
  }
  return result;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix tmp(columns_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      tmp.matrix_[j][i] = matrix_[i][j];
    }
  }
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() const {
  ValidateSquareMatrix();
  S21Matrix complements(rows_, columns_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      complements.matrix_[i][j] =
          CalculateMinor(i, j) * ((i + j) % 2 == 0 ? 1.0 : -1.0);
    }
  }
  return complements;
}

double S21Matrix::CalculateMinor(int row, int col) const {
  S21Matrix minor = CreateSubmatrix(row, col);
  return minor.Determinant();
}

S21Matrix S21Matrix::CreateSubmatrix(int excluded_row, int excluded_col) const {
  S21Matrix submatrix(rows_ - 1, columns_ - 1);
  for (int i = 0, sub_i = 0; i < rows_; ++i) {
    if (i == excluded_row) continue;
    for (int j = 0, sub_j = 0; j < columns_; ++j) {
      if (j == excluded_col) continue;
      submatrix.matrix_[sub_i][sub_j++] = matrix_[i][j];
    }
    ++sub_i;
  }
  return submatrix;
}

double S21Matrix::Determinant() const {
  ValidateSquareMatrix();
  if (rows_ == 1) return matrix_[0][0];
  if (rows_ == 2)
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  double det = 0.0;
  for (int i = 0; i < columns_; ++i) {
    det += matrix_[0][i] * CalculateMinor(0, i) * (i % 2 == 0 ? 1.0 : -1.0);
  }
  return det;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != columns_) throw std::invalid_argument("Matrix is not square");
  double determinant = Determinant();
  if (determinant == 0)
    throw std::invalid_argument(
        "Determinant is zero, InverseMatrix is unavailable");

  S21Matrix adjoint(rows_, columns_);
  adjoint = CalcComplements();
  adjoint = adjoint.Transpose();

  S21Matrix result(rows_, columns_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      result(i, j) = (1 / determinant) * adjoint(i, j);
    }
  }
  return result;
}

void S21Matrix::ValidateSameSize(const S21Matrix& other) const {
  if (rows_ != other.rows_ || columns_ != other.columns_) {
    throw std::invalid_argument("Matrix dimensions must match");
  }
}

void S21Matrix::ValidateSquareMatrix() const {
  if (rows_ != columns_) {
    throw std::invalid_argument("Matrix is not square");
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool equal = true;
  if (rows_ != other.GetRows() || columns_ != other.GetColumns()) {
    return false;
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < columns_; ++j) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        equal = false;
      }
    }
  }
  return equal;
}
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix tmp(*this);
  tmp.MulNumber(num);
  return tmp;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    FreeMatrix();
    rows_ = other.rows_;
    columns_ = other.columns_;
    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.columns_ = 0;
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;
  FreeMatrix();
  rows_ = other.rows_;
  columns_ = other.columns_;
  AllocateMatrix();
  for (int i = 0; i < rows_; ++i) {
    std::copy(other.matrix_[i], other.matrix_[i] + columns_, matrix_[i]);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(const int i, const int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= columns_) {
    throw std::out_of_range("Index is outside the matrix_");
  }
  return matrix_[i][j];
}
// Mutator
void S21Matrix::SetRows(int new_rows) {
  if (new_rows <= 0) {
    throw std::invalid_argument("Number of rows must be greater than zero.");
  }

  if (new_rows == rows_) {
    return;
  }

  double** new_matrix = new double*[new_rows];
  for (int i = 0; i < new_rows; ++i) {
    new_matrix[i] = new double[columns_]();
  }

  int min_rows = std::min(rows_, new_rows);
  for (int i = 0; i < min_rows; ++i) {
    for (int j = 0; j < columns_; ++j) {
      new_matrix[i][j] = matrix_[i][j];
    }
  }

  FreeMatrix();

  matrix_ = new_matrix;
  rows_ = new_rows;
}
void S21Matrix::SetColumns(int new_columns) {
  if (new_columns <= 0) {
    throw std::invalid_argument("Number of columns must be greater than zero.");
  }

  if (new_columns == columns_) return;

  double** new_matrix = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    new_matrix[i] = new double[new_columns]();
  }
  int min_columns = std::min(columns_, new_columns);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < min_columns; ++j) {
      new_matrix[i][j] = matrix_[i][j];
    }
  }
  FreeMatrix();
  matrix_ = new_matrix;
  columns_ = new_columns;
}