#ifndef S21_VECTOR_TPP
#define S21_VECTOR_TPP

#include "s21_vector.h"

using namespace s21;

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator& alloc)
    : alloc_(alloc), _size(0), data_(nullptr), _cap(0) {}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type count, const T& value,
                             const Allocator& alloc)
    : alloc_(alloc), _size(count), _cap(count), data_(alloc_.allocate(count)) {
  for (size_type i = 0; i < count; ++i) {
    alloc_.construct(&data_[i], value);
  }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(std::initializer_list<T> init,
                             const Allocator& alloc)
    : alloc_(alloc),
      _size(init.size()),
      _cap(init.size()),
      data_(alloc_.allocate(init.size())) {
  size_type i = 0;
  for (const T& item : init) {
    alloc_.construct(&data_[i++], item);
  }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector& other)
    : alloc_(other.alloc_),
      _size(other._size),
      _cap(other._cap),
      data_(alloc_.allocate(_cap)) {
  for (size_type i = 0; i < _size; ++i) {
    alloc_.construct(&data_[i], other.data_[i]);
  }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(vector&& other)
    : alloc_(other.alloc_),
      _size(other._size),
      _cap(other._cap),
      data_(other.data_) {
  other._size = 0;
  other._cap = 0;
  other.data_ = nullptr;
}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector() {
  if (data_) {
    for (size_t i = 0; i < _size; ++i) {
      alloc_.destroy(data_ + i);
    }
    alloc_.deallocate(data_, _cap);
  }
}
template <typename T, typename Allocator>
void vector<T, Allocator>::resize(size_type sz) {
  if (sz > _cap) {
    reserve(sz);
  }
  if (sz > _size) {
    for (size_type i = _size; i < sz; ++i) {
      alloc_.construct(&data_[i], T());
    }
  } else {
    for (size_type i = sz; i < _size; ++i) {
      alloc_.destroy(&data_[i]);
    }
  }

  _size = sz;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type cp) {
  if (cp > _cap) {
    pointer new_data = alloc_.allocate(cp);
    std::copy(data_, data_ + _size, new_data);
    alloc_.deallocate(data_, _cap);
    data_ = new_data;
    _cap = cp;
  }
}
template <typename T, typename Allocator>
T& vector<T, Allocator>::at(size_type pos) {
  if (pos >= _size) throw std::out_of_range("Out_of_range");

  return *(data_ + pos);
}
template <typename T, typename Allocator>
T& vector<T, Allocator>::front() {
  if (_size == 0) {
    throw std::out_of_range("vector is empty");
  }
  return *data_;
}

template <typename T, typename Allocator>
const T& vector<T, Allocator>::front() const {
  if (_size == 0) {
    throw std::out_of_range("vector is empty");
  }
  return *data_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
  return data_ + _size;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cend() {
  return data_ + _size;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
  return data_;
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cbegin() {
  return data_;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::assign(size_type count, const T& value) {
  clear();
  reserve(count);
  for (size_type i = 0; i < count; ++i) {
    alloc_.construct(&data_[i], value);
  }
  _size = count;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::swap(vector& other) {
  std::swap(data_, other.data_);
  std::swap(_size, other._size);
  std::swap(_cap, other._cap);
  std::swap(alloc_, other.alloc_);
}

template <typename T, typename Allocator>
void vector<T, Allocator>::clear() {
  resize(0);
}

template <typename T, typename Allocator>
T& vector<T, Allocator>::operator[](size_type pos) {
  return data_[pos];
}

template <typename T, typename Allocator>
const T& vector<T, Allocator>::operator[](size_type pos) const {
  return data_[pos];
}

template <typename T, typename Allocator>
T& vector<T, Allocator>::back() {
  return data_[_size - 1];
}

template <typename T, typename Allocator>
const T& vector<T, Allocator>::back() const {
  return data_[_size - 1];
}

template <typename T, typename Allocator>
T* vector<T, Allocator>::data() noexcept {
  return data_;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::empty() const {
  return size() == 0 ? true : false;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::shrink_to_fit() {
  if (_size < _cap) {
    vector<T> temp(_size);
    for (size_type i = 0; i < _size; ++i) {
      alloc_.construct(&temp.data_[i], std::move(data_[i]));
      alloc_.destroy(&data_[i]);
    }
    this->swap(temp);
  }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::push_back(const T& value) {
  if (_size == _cap) {
    size_type new_cap = (_cap == 0) ? 1 : _cap * 2;
    pointer new_data = alloc_.allocate(new_cap);

    for (size_type i = 0; i < _size; ++i) {
      alloc_.construct(&new_data[i], data_[i]);
      alloc_.destroy(&data_[i]);
    }

    if (data_) alloc_.deallocate(data_, _cap);

    data_ = new_data;
    _cap = new_cap;
  }

  alloc_.construct(&data_[_size], value);
  ++_size;
}

template <typename T, typename Allocator>
T* vector<T, Allocator>::insert(iterator pos, const T& value) {
  if (pos < begin() || pos >= end()) {
    throw std::out_of_range("Position out of range");
  }
  if (_size == _cap) {
    reserve((_cap == 0) ? 1 : _cap * 2);
  }
  size_t index = pos - begin();
  for (size_t i = _size; i > index; --i) {
    alloc_.construct(&data_[i], data_[i - 1]);
    alloc_.destroy(&data_[i - 1]);
  }
  alloc_.construct(&data_[index], value);
  ++_size;

  return data_ + index;
}

template <typename T, typename Allocator>
T* vector<T, Allocator>::erase(iterator pos) {
  if (pos < begin() || pos >= end()) {
    throw std::out_of_range("Position out of range");
  }
  size_t index = pos - begin();
  alloc_.destroy(&data_[index]);
  for (size_t i = index; i < _size - 1; ++i) {
    alloc_.construct(&data_[i], std::move(data_[i + 1]));
    alloc_.destroy(&data_[i + 1]);
  }

  --_size;
  return data_ + index;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back() {
  alloc_.destroy(&data_[_size - 1]);
  --_size;
}

template <typename T, typename Allocator>
template <class... Args>
T* vector<T, Allocator>::emplace(const_iterator pos, Args&&... args) {
  if (pos < begin() || pos >= end()) {
    throw std::out_of_range("Position out of range");
  }
  if (_size == _cap) {
    reserve((_cap == 0) ? 1 : _cap * 2);
  }
  size_t index = pos - begin();
  for (size_t i = _size; i > index; --i) {
    alloc_.construct(&data_[i], std::move(data_[i - 1]));
    alloc_.destroy(&data_[i - 1]);
  }
  alloc_.construct(&data_[index], std::forward<Args>(args)...);
  ++_size;

  return data_ + index;
}

template <typename T, typename Allocator>
template <class... Args>
void vector<T, Allocator>::emplace_back(Args&&... args) {
  emplace(end(), std::forward<Args>(args)...);
}

#endif
