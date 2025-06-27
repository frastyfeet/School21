#include <iostream>
#include <string>

#include "s21_map.h"

using namespace s21;

int main() {
  map<std::string, int> age = {{"Alex", 21}, {"Vanek", 322}, {"Serega", 228}};

  map<std::string, int> age2;

  // age.insert({"Alex", 21});
  // age.insert({"Vanek", 322});
  // age.insert({"Serega", 228});

  age.swap(age2);
  auto iter = age.find("Alex");

  std::cout << (*iter).first << std::endl;

  age["Aabb"];

  age.erase(iter);

  age.clear();

  for (auto [name, num] : age2) {
    std::cout << name << " " << num << std::endl;
  }

  std::cout << age.max_size();
}
