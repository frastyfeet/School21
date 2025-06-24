#include <iostream>
#include <string>

#include "s21_map.h"

using namespace s21;

int main()
{

    map<std::string, int> age;

    age.insert({"Alex", 21});
    age.insert({"Vanek", 322});
    age.insert({"Serega", 228});

    age.find("Alex");

    // std::cout << age.tree.root->right->value.first;
}
