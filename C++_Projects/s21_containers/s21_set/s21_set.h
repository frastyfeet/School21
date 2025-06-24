#ifndef S21_SET_H
#define S21_SET_H

#include <iterator>

#include "../s21_tree/s21_tree.h"

namespace s21 {

template <typename Key>
class set {
 public:
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;
  using iterator = typename RBtree<Key>::TreeIterator;
  using const_iterator = typename RBtree<Key>::Const_TreeIterator;

  set() = default;
  set(std::initializer_list<value_type> const& items);
  set(const Key& value);
  set(const set& other);
  set(set&& other) noexcept;

  ~set() = default;

  set& operator=(const set& other);

  void swap(set& other);

  void clear();

  std::pair<iterator, bool> insert(const value_type& value);
  iterator erase(iterator pos);

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  iterator begin() { return tree.begin(); }
  iterator end() { return tree.end(); }
  const_iterator cbegin() const { return tree.cbegin(); }
  const_iterator cend() const { return tree.cend(); }

  iterator find(const Key& key);
  bool contains(const Key& key) const;
  size_type count(const Key& key) const;

  void printTree() { tree.printHelper(tree.getRoot(), "", true); }

 private:
  RBtree<Key> tree;
};

}  // namespace s21

#include "s21_set.tpp"

#endif