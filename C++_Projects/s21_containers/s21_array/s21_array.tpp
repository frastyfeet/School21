#ifndef S21_ARRAY_TPP
#define S21_ARRAY_TPP

#include "s21_array.h"

using namespace s21;

template <typename T, std::size_t N>
array<T, N>::array() : _size(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<T> const &items) : _size(N) {
  for (size_type i = 0; i < items.size(); ++i) {
    data_[i] = *(items.begin() + i);
  }
}

template <typename T, std::size_t N>
array<T, N>::array(const array &a) {
  std::copy(a.data_, a.data_ + N, data_);
}

template <typename T, std::size_t N>
array<T, N>::array(array &&a) {
  std::swap(data_, a.data_);
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return _size;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return _size;
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Out of array range");
  }

  return data_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::array &array<T, N>::operator=(const array<T, N> &other) {
  array<T, N> new_arr = other;
  swap(new_arr);
  return *this;
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; ++i) {
    data_[i] = value;
  }
}

template <typename T, std::size_t N>
constexpr bool array<T, N>::empty() const noexcept {
  return !size();
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (!(pos < _size)) {
    throw std::out_of_range("Out of array range");
  }

  return data_[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return data_;
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  return data_[N - 1];
}

template <typename T, std::size_t N>
void array<T, N>::swap(array &other) {
  std::swap(_size, other._size);
  std::swap(data_, other.data_);
}

template <typename T, std::size_t N>
bool array<T, N>::operator>(const array<T, N> &other) {
  for (size_t i = 0; i < N; ++i) {
    if (this->data_[i] > other.data_[i]) {
      return true;
    }
  }
  return false;
}
template <typename T, std::size_t N>
bool array<T, N>::operator==(const array<T, N> &other) {
  for (size_t i = 0; i < N; ++i) {
    if (this->data_[i] != other.data_[i]) {
      return false;
    }
  }
  return true;
}
template <typename T, std::size_t N>
bool array<T, N>::operator!=(const array<T, N> &other) {
  for (size_t i = 0; i < N; ++i) {
    if (this->data_[i] != other.data_[i]) {
      return true;
    }
  }
  return false;
}
template <typename T, std::size_t N>
bool array<T, N>::operator<(const array<T, N> &other) {
  for (size_t i = 0; i < N; ++i) {
    if (this->data_[i] < other.data_[i]) {
      return true;
    }
  }
  return false;
}

#endif  // S21_ARRAY_TPP
