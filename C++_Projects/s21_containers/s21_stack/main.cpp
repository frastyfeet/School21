#include "s21_stack.h"

int main() {
  s21::stack<int> st = {1, 2, 3, 4};

  std::cout << st.top();

  return 0;
}