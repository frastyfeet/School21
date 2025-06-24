#ifndef S21_LIST_TPP
#define S21_LIST_TPP
#include "s21_list.h"

using namespace s21;

template <typename T>
list<T>::list() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
list<T>::list(const list& other) : _size(0), _head(nullptr), _tail(nullptr) {
  Node* current = other._head;
  while (current != nullptr) {
    push_back(current->value);
    current = current->next;
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const& items) : list() {
  for (auto& item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(size_type count) : _size(0), _head(nullptr), _tail(nullptr) {
  for (size_t i = 0; i < count; ++i) {
    push_back(T());
  }
}

template <typename T>
list<T>::list(list&& other)
    : _size(other._size), _head(other._head), _tail(other._tail) {
  other._head = nullptr;
  other._tail = nullptr;
  other._size = 0;
}

template <typename T>
list<T>::~list() {
  while (_head) {
    Node* tmp = _head;
    _head = _head->next;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    delete tmp;
  }
}

template <typename T>
size_t list<T>::size() const {
  return _size;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(Node);
}

template <typename T>
bool list<T>::empty() const {
  return _size == 0;
}

template <typename T>
void list<T>::swap(list& other) {
  std::swap(this->_head, other._head);
  std::swap(this->_tail, other._tail);
  std::swap(this->_size, other._size);
}

template <typename T>
list<T>& list<T>::operator=(const list& other) {
  if (this != &other) {
    list temp(other);
    swap(temp);
  }
  return *this;
}

template <typename T>
T& list<T>::front() {
  return _head->value;
}

template <typename T>
T& list<T>::back() {
  return _tail->value;
}

template <typename T>
void list<T>::clear() {
  while (_head) {
    Node* tmp = _head;
    _head = _head->next;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    delete tmp;
  }
  _size = 0;
  _tail = nullptr;
  _head = nullptr;
}

template <typename T>
void list<T>::resize(size_type count) {
  if (count > _size) {
    for (size_type i = _size; i < count; ++i) {
      push_back(T());
    }
  } else if (count < _size) {
    while (_size > count) {
      pop_back();
    }
  }
}

template <typename T>
void list<T>::assign(size_type count, const T& value) {
  clear();
  for (size_t i = 0; i < count; ++i) {
    push_back(value);
  }
}

template <typename T>
void list<T>::push_back(const T& value) {
  Node* new_node = new Node(value);
  new_node->prev = _tail;
  new_node->next = nullptr;

  if (_head == nullptr) {
    _head = new_node;
    _tail = new_node;
  } else {
    _tail->next = new_node;
    _tail = new_node;
  }
  ++_size;
}

template <typename T>
void list<T>::push_front(const T& value) {
  Node* new_node = new Node(value);
  new_node->prev = nullptr;
  new_node->next = _head;

  if (_head != nullptr) {
    _head->prev = new_node;
  } else {
    _tail = new_node;
  }

  _head = new_node;
  ++_size;
}

template <typename T>
void list<T>::pop_back() {
  if (_tail == nullptr) {
    throw std::out_of_range("list is empty");
  }
  Node* delete_node = _tail;
  _tail = _tail->prev;
  if (_tail) {
    _tail->next = nullptr;
  } else {
    _head = nullptr;
  }
  --_size;
  delete delete_node;
}

template <typename T>
void list<T>::pop_front() {
  if (_head == nullptr) {
    throw std::out_of_range("list is empty");
  }
  Node* delete_node = _head;
  _head = _head->next;
  if (_head) {
    _head->prev = nullptr;
  } else {
    _tail = nullptr;
  }
  --_size;
  delete delete_node;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(_head);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(nullptr);
}

template <typename T>
typename list<T>::Const_Iterator list<T>::begin() const {
  return iterator(_head);
}

template <typename T>
typename list<T>::Const_Iterator list<T>::end() const {
  return iterator(nullptr);
}

template <typename T>
typename list<T>::iterator list<T>::erase(iterator pos) {
  Node* ptr = pos.current;
  Node* return_Node = nullptr;

  if (ptr == _head) {
    pop_front();
    return_Node = _head;
  } else if (ptr == _tail) {
    pop_back();
    return_Node = nullptr;
  } else {
    return_Node = ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

    delete ptr;
    --_size;
  }

  return iterator(return_Node);
}

template <typename T>
typename list<T>::iterator list<T>::insert(const_iterator pos, const T& value) {
  Node* ptr = pos.current;
  Node* return_Node = nullptr;
  ;

  if (ptr == _head) {
    push_front(value);
    return_Node = _head;
  } else if (ptr == nullptr) {
    push_back(value);
    return_Node = _tail;
  } else {
    Node* prev_ptr = ptr->prev;
    Node* new_node = new Node(value);
    ptr->prev = new_node;
    prev_ptr->next = new_node;
    new_node->next = ptr;
    new_node->prev = prev_ptr;
    ++_size;
    return_Node = new_node;
  }

  return iterator(return_Node);
}

template <typename T>
void list<T>::merge(list& other) {
  auto iter2 = other.begin();
  while (iter2 != other.end()) {
    push_back(*iter2);
    ++iter2;
  }
  other.clear();
  sort();
}

template <typename T>
void list<T>::sort() {
  for (auto iter = begin(); iter != end(); ++iter) {
    for (auto iter2 = begin(); iter2 != end(); ++iter2) {
      if (*iter < *iter2) {
        std::swap(*iter, *iter2);
      }
    }
  }
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (other.empty()) return;

  Node* pos_node = pos.current;

  if (pos_node == _head) {
    other._tail->next = _head;
    if (_head != nullptr) {
      _head->prev = other._tail;
    }
    _head = other._head;
    if (_tail == nullptr) {
      _tail = other._tail;
    }
  } else {
    Node* prev_node = pos_node->prev;

    prev_node->next = other._head;
    other._head->prev = prev_node;

    other._tail->next = pos_node;
    pos_node->prev = other._tail;
  }

  _size += other._size;

  other._head = nullptr;
  other._tail = nullptr;
  other._size = 0;
}

template <typename T>
void list<T>::remove(const T& value) {
  auto iter = begin();
  while (iter != end()) {
    if (*iter == value) {
      iter = erase(iter);
    } else {
      ++iter;
    }
  }
}

template <typename T>
void list<T>::unique() {
  auto iter = begin();

  while (iter != end()) {
    auto next_iter = iter;
    ++next_iter;
    if (next_iter != end() && *next_iter == *iter) {
      erase(next_iter);
    } else {
      ++iter;
    }
  }
}

template <typename T>
void list<T>::reverse() {
  Node* ptr = _head;
  Node* next = nullptr;
  for (size_t i = 0; i < _size; ++i) {
    next = ptr->next;
    std::swap(ptr->next, ptr->prev);
    ptr = next;
  }
  std::swap(_head, _tail);
}

#endif