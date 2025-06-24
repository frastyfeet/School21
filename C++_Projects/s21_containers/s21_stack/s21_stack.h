#ifndef S21_STACK_H
#define S21_STACK_H

#include "../s21_list/s21_list.h"

namespace s21 {
template <typename T>
class stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  stack() : data_() {}
  stack(std::initializer_list<value_type> const& items) : data_(items) {}
  stack(const stack& s) : data_(s.data_) {}
  stack(stack&& s) : data_(std::move(s.data_)) {}
  ~stack() = default;

  stack& operator=(const stack& other) {
    data_ = other.data_;
    return *this;
  }
  stack& operator=(stack&& s) {
    data_ = std::move(s.data_);
    return *this;
  }
  reference top() { return data_.back(); }
  const_reference top() const { return data_.back(); }

  bool empty() const { return data_.empty(); }
  size_type size() const { return data_.size(); }

  void push(const value_type& value) { data_.push_back(value); }
  void pop() { data_.pop_back(); }
  void swap(stack& other) noexcept { data_.swap(other.data_); }

 private:
  list<T> data_;
};

}  // namespace s21

#endif