#include "s21_set.h"

namespace s21 {

template <typename Key>
set<Key>::set(const Key& value) : tree(value) {}

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const& items) : tree(items) {}

template <typename Key>
set<Key>::set(const set& other) : tree(other.tree) {}

template <typename Key>
set<Key>::set(set&& other) noexcept : tree(std::move(other.tree)) {}

template <typename Key>
set<Key>& set<Key>::operator=(const set& other) {
  tree = other.tree;
  return *this;
}

template <typename Key>
void set<Key>::clear() {
  tree.clear(tree.root);
  tree.root = RBtree<Key>::NIL;
  tree.tree_size = 0;
}

template <typename Key>
void set<Key>::swap(set& other) {
  std::swap(tree.root, other.tree.root);
  std::swap(tree.tree_size, other.tree.tree_size);
}

template <typename Key>
bool set<Key>::empty() const {
  return tree.empty();
}

template <typename Key>
typename set<Key>::size_type set<Key>::size() const {
  return tree.size();
}

template <typename Key>
typename set<Key>::size_type set<Key>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(RBtree<Key>);
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const Key& value) {
  typename RBtree<Key>::Node* result = tree.insert(value);
  bool inserted = (result != nullptr);
  return {iterator(result), inserted};
}

template <typename Key>
typename set<Key>::iterator set<Key>::erase(typename set<Key>::iterator pos) {
  if (pos == this->end()) return this->end();
  iterator next = pos;
  ++next;
  tree.erase(*pos);
  return next;
}

template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key& key) {
  return iterator(tree.findNode(key));
}
template <typename Key>
bool set<Key>::contains(const Key& key) const {
  return tree.findNode(key) != RBtree<Key>::NIL;
}

template <typename Key>
std::size_t set<Key>::count(const Key& key) const {
  return contains(key) ? 1 : 0;
}

}  // namespace s21