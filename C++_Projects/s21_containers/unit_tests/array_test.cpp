#include <gtest/gtest.h>

#include <array>
#include "../s21_array/s21_array.h"

TEST(ArrayTest, DefaultConstructor)
{
    s21::array<int, 5> arr;
    std::array<int, 5> arr2;
    ASSERT_EQ(arr.size(), arr2.size());
}

TEST(ArrayTest, ParametrizedConstructor)
{
    s21::array<int, 5> arr{1, 2, 3, 4, 5};
    std::array<int, 5> arr2{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr[i], arr2[i]);
    }
}

TEST(ArrayTest, CopyConstructor)
{
    s21::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2{1, 2, 3, 4, 5};
    s21::array<int, 5> arr3(arr1);
    std::array<int, 5> arr4(arr2);
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr2[i], arr3[i]);
    }
}

TEST(ArrayTest, MoveConstructor)
{
    s21::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2{1, 2, 3, 4, 5};
    s21::array<int, 5> arr3(std::move(arr1));
    std::array<int, 5> arr4(std::move(arr2));
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr3[i], arr4[i]);
    }
    ASSERT_EQ(arr1.size(), 5);
}

TEST(ArrayTest, CopyAssignmentOperator)
{
    s21::array<int, 5> arr1{1, 2, 3, 4, 5};
    s21::array<int, 5> arr2;
    std::array<int, 5> arr3{1, 2, 3, 4, 5};
    std::array<int, 5> arr4;
    arr4 = arr3;
    arr2 = arr1;
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr2[i], arr4[i]);
    }
    ASSERT_EQ(arr1.size(), 5);
}

TEST(ArrayTest, MoveAssignmentOperator)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    int a = arr[0], b = arr2[0];
    ;
    ASSERT_EQ(a, b);
}

TEST(ArrayTest, IteratorBegin)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    auto iter = arr.begin();
    auto iter2 = arr2.begin();
    ASSERT_EQ(*iter, *iter2);
}

TEST(ArrayTest, RangeBasedIterator)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    auto iter = arr2.begin();
    for (const auto &elem : arr)
    {
        ASSERT_EQ(elem, *iter);
        iter++;
    }
}

TEST(ArrayTest, Method_at)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr.at(i), arr2.at(i));
    }
}

TEST(ArrayTest, Method_front)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr.front(), arr2.front());
}

TEST(ArrayTest, Method_back)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr.back(), arr2.back());
}

TEST(ArrayTest, Method_empty)
{
    s21::array<int, 5> arr;
    std::array<int, 5> arr2;
    ASSERT_EQ(arr.empty(), arr2.empty());
}

TEST(ArrayTest, Method_size)
{
    s21::array<int, 5> arr;
    std::array<int, 5> arr2;
    ASSERT_EQ(arr.size(), arr2.size());
}

TEST(ArrayTest, Method_max_size)
{
    s21::array<int, 5> arr;
    std::array<int, 5> arr2;
    ASSERT_EQ(arr.max_size(), arr2.max_size());
}

TEST(ArrayTest, Method_fill)
{
    s21::array<int, 5> arr;
    std::array<int, 5> arr2;
    arr.fill(1);
    arr2.fill(1);
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr[i], arr2[i]);
        ASSERT_EQ(arr.size(), arr2.size());
    }
}

TEST(ArrayTest, Method_swap)
{
    s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    s21::array<int, 5> arr2 = {6, 7, 8, 9, 10};
    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr4 = {6, 7, 8, 9, 10};
    arr1.swap(arr2);
    arr3.swap(arr4);
    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(arr1[i], arr3[i]);
        ASSERT_EQ(arr2[i], arr4[i]);
    }
    ASSERT_EQ(arr1.size(), arr3.size());
    ASSERT_EQ(arr2.size(), arr4.size());
}

TEST(ArrayTest, Method_data)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    ASSERT_EQ(*arr.data(), *arr2.data());
}

TEST(ArrayTest, OperatorEqual)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    s21::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr4 = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr == arr2, arr3 == arr4);
}

TEST(ArrayTest, OperatorNotEqual)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    s21::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr4 = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr != arr2, arr3 != arr4);
}

TEST(ArrayTest, OperatorLess)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    s21::array<int, 5> arr2 = {5, 4, 3, 2, 1};
    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr4 = {5, 4, 3, 2, 1};
    ASSERT_EQ(arr < arr2, arr3 < arr4);
    ASSERT_EQ(arr2 < arr, arr4 < arr3);
}

TEST(ArrayTest, OperatorMore)
{
    s21::array<int, 5> arr = {1, 2, 3, 4, 5};
    s21::array<int, 5> arr2 = {5, 4, 3, 2, 1};
    std::array<int, 5> arr3 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr4 = {5, 4, 3, 2, 1};
    ASSERT_EQ(arr > arr2, arr3 > arr4);
}
