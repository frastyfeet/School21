#include <iostream>

#include "s21_tree.h"

int main() {
  s21::RBtree<int> tree = {1, 23, 4, 5};

  s21::RBtree<int> tree2;

  tree2 = tree;
  tree2.printHelper(tree2.getRoot(), "", true);

  tree2.insert(100);

  return 0;
}
