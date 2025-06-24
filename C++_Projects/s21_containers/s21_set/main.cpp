#include <gtest/gtest.h>

#include "s21_set.h"

int main() {
  s21::set<int> st = {1, 5, 87, 5, 23, 3};
  st.find(10);
  st.printTree();
}
