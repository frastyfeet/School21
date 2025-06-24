#ifndef S21_list_H
#define S21_list_H
#include <iostream>
#include <limits>
#include <utility>

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using size_type = std::size_t;
  using reference = value_type&;
  using const_reference = const value_type&;

  explicit list();
  explicit list(size_type count);
  list(std::initializer_list<value_type> const& items);
  list(const list& other);
  list(list&& other);

  ~list();

  size_type size() const;
  size_type max_size() const;
  bool empty() const;
  void clear();
  void resize(size_type count);

  list& operator=(const list& other);
  void push_front(const T& value);
  void push_back(const T& value);
  void pop_front();
  void pop_back();
  void assign(size_type count, const T& value);

  void swap(list& other);

  reference front();
  reference back();

 private:
  struct Node {
    T value;
    Node* next;
    Node* prev;

    Node() : value(T()), next(nullptr), prev(nullptr) {}
    Node(const T& val) : value(val), next(nullptr), prev(nullptr) {}
  };

  Node* _head = nullptr;
  Node* _tail = nullptr;
  size_type _size = 0;

 public:
  class Iterator {
   public:
    Iterator(Node* ptr) : current(ptr) {}
    T& operator*() const { return current->value; }
    Iterator& operator++() {
      current = current->next;
      return *this;
    }
    Iterator& operator--() {
      current = current->prev;
      return *this;
    }
    bool operator==(const Iterator& other) const {
      return current == other.current;
    }
    bool operator!=(const Iterator& other) const {
      return current != other.current;
    }

   protected:
    Node* current;
    friend class list<T>;
    friend class Const_Iterator;
  };

  class Const_Iterator : public Iterator {
   public:
    using Iterator::Iterator;
    Const_Iterator(const Iterator& other) : Iterator(other) {}
    const T& operator*() const { return this->current->value; }

   protected:
    friend class list<T>;
  };

  using iterator = Iterator;
  using const_iterator = Const_Iterator;

  iterator begin();
  iterator end();

  const_iterator begin() const;
  const_iterator end() const;

  iterator erase(iterator pos);
  iterator insert(const_iterator pos, const T& value);

  void merge(list& other);
  void sort();
  void splice(const_iterator pos, list& other);
  void remove(const T& value);
  void unique();
  void reverse();

  //  по желанию можно реализовать, не знаю обязательно ли это
  // template <typename... Args>
  // iterator emplace(const_iterator pos, Args&&... args);
  // emplate< class... Args >
  // void emplace_back( Args&&... args );
  // template< class... Args >
  // void emplace_front( Args&&... args );
};

#include "s21_list.tpp"

}  // namespace s21

#endif