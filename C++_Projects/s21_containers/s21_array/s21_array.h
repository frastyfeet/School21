#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <cstddef>
#include <iostream>

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  size_type size() const;
  size_type max_size();

  array();
  array(std::initializer_list<T> const &items);
  array(const array &a);
  array(array &&a);
  ~array() = default;

  array &operator=(const array &other);
  reference operator[](size_t pos);
  const_reference operator[](size_t pos) const;

  iterator begin() { return data_; };
  iterator end() { return data_ + N; };

  const_reference front();
  const_reference back();
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  constexpr bool empty() const noexcept;

  void fill(const_reference value);
  void swap(array &other);
  iterator data() noexcept { return data_; };
  iterator data() const noexcept { return data_; };

  bool operator==(const array<T, N> &other);
  bool operator!=(const array<T, N> &other);
  bool operator<(const array<T, N> &other);
  bool operator>(const array<T, N> &other);

 private:
  size_type _size = N;
  value_type data_[N];
};

#include "s21_array.tpp"

}  // namespace s21

#endif  // S21_ARRAY_H
