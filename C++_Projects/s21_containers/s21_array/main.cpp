#include "s21_array.h"
#include <string>
#include <array>


int main(){

    // s21::array<int,5> s = {1,2,3,4,5};
    // s21::array<int,5> s2;

    std::array<int,5> s = {1,2,3,4,5};
    std::array<int,5> s2 {};
    
    std::cout << s.max_size();
    return 0;
}