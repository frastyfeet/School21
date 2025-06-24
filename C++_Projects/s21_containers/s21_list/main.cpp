#include "s21_list.h"

int main() {
  s21::List<int> lis = {1, 1, 1, 2, 2, 2, 3, 3, 3};
  s21::List<int> lis2 = {9, 2, 3, 5};
  auto it = lis.begin();
  s21::list lis.reverse();

  for (auto elem : lis) {
    std::cout << elem << " ";
  }
  std::cout << std::endl << lis.size() << std::endl;
}
