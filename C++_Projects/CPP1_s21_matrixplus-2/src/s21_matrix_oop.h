#ifndef S21Matrix_H
#define S21Matrix_H

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_;
  int columns_;
  double** matrix_;

 public:
  void AllocateMatrix();
  void FreeMatrix();
  void CopyData(
      const S21Matrix& other);  // Добавлена функция копирования данных
  void ValidateSameSize(
      const S21Matrix& other) const;  // Валидация на одинаковый размер
  void ValidateSquareMatrix() const;  // Валидация на квадратную матрицу
  double MultiplyRowByColumn(
      const S21Matrix& m1, const S21Matrix& m2, int row,
      int col) const;  // Вспомогательная функция для умножения
  S21Matrix CreateSubmatrix(int excluded_row,
                            int excluded_col) const;  // Создание подматрицы
  double CalculateMinor(int row, int col) const;  // Расчет минора

  S21Matrix();  // Конструктор по умолчанию
  S21Matrix(int rows, int columns);  // Конструктор с размерами
  S21Matrix(const S21Matrix& other);  // Конструктор копирования
  S21Matrix(S21Matrix&& other) noexcept;  // Конструктор перемещения
  ~S21Matrix();                           // Деструктор

  int GetRows() const noexcept { return rows_; }        // Accessor 1
  int GetColumns() const noexcept { return columns_; }  // Accessor 2
  void SetRows(int new_rows);                           // Mutator 1
  void SetColumns(int columns);                         // Mutator 2

  // matrix_func
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;
  bool EqMatrix(const S21Matrix& other) const;
  // operators
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(double num) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(double num);
  double& operator()(int row, int column);
  double operator()(int row, int column) const;
};

#endif
