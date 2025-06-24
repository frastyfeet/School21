#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "../s21_list/s21_list.h"

namespace s21 {

template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  queue() : data_() {}
  queue(std::initializer_list<value_type> const& items) : data_(items) {}
  queue(const queue& s) : data_(s.data_) {}
  queue(queue&& s) : data_(std::move(s.data_)) {}
  ~queue() = default;

  queue& operator=(const queue& other) {
    data_ = other.data_;
    return *this;
  }
  queue& operator=(queue&& s) {
    data_ = std::move(s.data_);
    return *this;
  }

  reference front() { return data_.front(); }
  const_reference front() const { return data_.front(); }
  reference back() { return data_.back(); }
  const_reference back() const { return data_.back(); }

  bool empty() const { return data_.empty(); }
  size_type size() const { return data_.size(); }

  void push(const value_type& value) { data_.push_back(value); }
  void pop() { data_.pop_front(); }
  void swap(queue& other) noexcept { data_.swap(other.data_); }

 private:
  list<T> data_;
};

}  // namespace s21

#endif