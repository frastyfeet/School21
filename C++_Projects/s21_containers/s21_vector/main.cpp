#include <iostream>
#include <set>
#include <string>

#include "s21_vector.h"

using namespace std;

int main() {
  s21::vector<std::string> vec1;

  vec1.push_back("52");
  vec1.push_back("52");
  vec1.push_back("52");
  std::cout << "Push: " << vec1[0] << ' ' << vec1.size() << " "
            << vec1.capacity() << endl;
  const auto it = vec1.cend();
  vec1.emplace_back("xuo");
  std::cout << "emplace_back: " << vec1[1] << ' ' << vec1.size() << " "
            << vec1.capacity() << endl;
  for (auto elem : vec1) {
    std::cout << elem << " ";
  }
}