#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <iostream>
#include <memory>

namespace s21 {

template <typename T, typename Allocator = std::allocator<T>>
class vector {
 public:
  using value_type = T;
  using allocator_type = Allocator;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = T&;
  using const_reference = const T&;
  using pointer = typename std::allocator_traits<Allocator>::pointer;
  using const_pointer =
      typename std::allocator_traits<Allocator>::const_pointer;
  using iterator = value_type*;
  using const_iterator = const iterator;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  explicit vector(const Allocator& alloc = Allocator());
  explicit vector(size_type count, const T& value = T(),
                  const Allocator& alloc = Allocator());
  vector(const vector& others);
  vector(vector&& other);
  vector(std::initializer_list<T> init, const Allocator& alloc = Allocator());
  ~vector();

  void assign(size_type count, const T& value);
  void swap(vector& other);
  void clear();

  size_type size() const { return _size; }
  size_type capacity() const { return _cap; }
  size_type max_size() const { return alloc_.max_size(); }
  void resize(size_type sz);
  void reserve(size_type cp);

  iterator begin();
  const_iterator cbegin();
  iterator end();
  const_iterator cend();

  reference front();
  reference back();
  reference at(size_type pos);
  reference operator[](size_type pos);
  T* data() noexcept;

  const_reference front() const;
  const_reference back() const;
  const_reference at(size_type pos) const;
  const_reference operator[](size_type pos) const;

  template <class... Args>
  iterator emplace(const_iterator pos, Args&&... args);

  template <class... Args>
  void emplace_back(Args&&... args);

  iterator insert(iterator pos, const T& value);
  iterator erase(iterator pos);

  bool empty() const;
  void shrink_to_fit();

  void push_back(const T& value);
  void pop_back();

 private:
  pointer data_;
  size_type _size;
  size_type _cap;
  allocator_type alloc_;
};

}  // namespace s21
#include "s21_vector.tpp"

#endif