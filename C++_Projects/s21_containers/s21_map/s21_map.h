#ifndef S21_MAP_H
#define S21_MAP_H

#include <initializer_list>
#include <iterator>

#include "../s21_tree/s21_tree.h"

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using value_type = std::pair<const Key, T>;
  using key_type = Key;
  using mapped_type = T;
  using iterator = typename RBtree<value_type>::TreeIterator;
  using const_iterator = typename RBtree<value_type>::Const_TreeIterator;
  using size_type = std::size_t;
  using reference = value_type &;
  using const_reference = const value_type &;

  map() = default;
  map(const map &m) : tree(m.tree) {}
  map(map &&m) : tree(std::move(m.tree)) {}
  map(std::initializer_list<value_type> const &items) {
    for (const auto &item : items) {
      insert(item);
    }
  }
  ~map() = default;

  map &operator=(map &m) {
    tree = m.tree;
    return *this;
  }

  T &operator[](const Key &key) {
    value_type value = {key, mapped_type{}};
    iterator it = map_find(key);
    if (it == tree.end()) {
      auto res = tree.insert(value);
      return res->value.second;
    }
    return (*it).second;
  }

  std::pair<iterator, bool> insert(const value_type &value) {
    auto result = tree.insert(value);
    bool inserted = (result != nullptr);
    return {iterator(result), inserted};
  }

  T &at(const Key &key) {
    iterator it = map_find(key);
    if (it == tree.end()) throw std::out_of_range("map::at");
    return (*it).second;
  }

  const T &at(const Key &key) const {
    const_iterator it = map_find(key);
    if (it == tree.end()) throw std::out_of_range("map::at");
    return (*it).second;
  }

  iterator find(const Key &key) { return map_find(key); }
  void erase(iterator pos) {
    auto it = map_find((*pos).first);
    if (it != end()) tree.erase(*pos);
  }

  void clear() {
    tree.clear(tree.root);
    tree.root = RBtree<value_type>::NIL;
    tree.tree_size = 0;
  }

  void swap(map &other) {
    std::swap(tree.root, other.tree.root);
    std::swap(tree.tree_size, other.tree.tree_size);
  }

  iterator begin() { return tree.begin(); }
  iterator end() { return tree.end(); }
  const_iterator begin() const noexcept { return tree.begin(); }
  const_iterator end() const noexcept { return tree.end(); }

  size_type size() { return tree.size(); }
  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(RBtree<value_type>);
  }
  bool empty() const { return tree.empty(); }

 private:
  RBtree<value_type> tree;

  iterator map_find(const Key &key) noexcept {
    iterator it = tree.begin();
    if (it == tree.end()) return end();
    while (it != tree.end()) {
      if ((*it).first == key) return it;
      it++;
    }
    return end();
  }
};

}  // namespace s21

#endif