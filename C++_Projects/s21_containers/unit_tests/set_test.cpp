#include <gtest/gtest.h>

#include <set>
#include "../s21_set/s21_set.h"

TEST(SetTest, ParametrizedConstructor)
{
    s21::set<int> st = {1, 2, 3, 4, 5};
    std::set<int> st2 = {1, 2, 3, 4, 5};

    auto it1 = st.begin();
    auto it2 = st2.begin();

    for (; it1 != st.end() && it2 != st2.end(); ++it1, ++it2)
    {
        ASSERT_EQ(*it1, *it2);
    }

    ASSERT_EQ(it1, st.end());
    ASSERT_EQ(it2, st2.end());
}

TEST(SetTest, CopyConstructor)
{
    s21::set<int> st = {1, 2, 3, 4, 5};
    std::set<int> st2 = {1, 2, 3, 4, 5};
    s21::set<int> st3 = st;
    std::set<int> st4 = st2;

    auto it1 = st3.begin();
    auto it2 = st4.begin();

    for (; it1 != st.end() && it2 != st2.end(); ++it1, ++it2)
    {
        ASSERT_EQ(*it1, *it2);
    }
}

TEST(SetTest, MoveConstructor)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};
    s21::set<int> st3(std::move(st));
    std::set<int> st4(std::move(st2));

    auto it1 = st3.begin();
    auto it2 = st4.begin();

    for (; it1 != st.end() && it2 != st2.end(); ++it1, ++it2)
    {
        ASSERT_EQ(*it1, *it2);
    }
}

TEST(SetTest, CopyAssignmentOperator)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};
    s21::set<int> st3;
    std::set<int> st4;
    st3 = st;
    st4 = st2;

    auto it1 = st3.begin();
    auto it2 = st4.begin();

    for (; it1 != st.end() && it2 != st2.end(); ++it1, ++it2)
    {
        ASSERT_EQ(*it1, *it2);
    }
}

TEST(SetTest, IteratorBegin)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};
    auto iter = st.begin();
    auto iter2 = st2.begin();
    ASSERT_EQ(*iter, *iter2);
}

TEST(SetTest, RangeBasedIterator)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};
    auto iter = st2.begin();
    for (const auto &elem : st)
    {
        ASSERT_EQ(elem, *iter);
        iter++;
    }
}

TEST(SetTest, Method_empty)
{
    s21::set<int> st;
    std::set<int> st2;
    ASSERT_EQ(st.empty(), st2.empty());
}

TEST(SetTest, Method_size)
{
    s21::set<int> st;
    std::set<int> st2;
    ASSERT_EQ(st.size(), st2.size());
}

// TEST(SetTest, Method_max_size)
// {
//     s21::set<int> st;
//     std::set<int> st2;
//     ASSERT_EQ(st.max_size(), st2.max_size());
// } неверное отображение, исправить

TEST(SetTest, Method_find)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};

    auto iter = st.find(4);
    auto iter2 = st2.find(4);

    ASSERT_EQ(*iter, *iter2);
}

TEST(SetTest, Method_contains)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};

    bool st_1 = st.contains(3);
    bool st_2 = st2.contains(3);

    ASSERT_EQ(st_1, st_2);
}

TEST(SetTest, Method_count)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};

    std::size_t sz1 = st.count(4);
    std::size_t sz2 = st2.count(4);

    ASSERT_EQ(sz1, sz2);
}

TEST(SetTest, Method_insert)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};

    auto iter = st.insert(10);
    auto iter2 = st2.insert(10);

    ASSERT_EQ(*iter.first, *iter2.first);
}

TEST(SetTest, Method_erase)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};

    auto iter = st.begin();
    auto iter2 = st2.begin();

    iter = st.erase(iter);
    iter2 = st2.erase(iter2);

    ASSERT_EQ(*iter, *iter2);
}

TEST(SetTest, Method_swap)
{
    s21::set<int> st{1, 2, 3, 4, 5};
    std::set<int> st2{1, 2, 3, 4, 5};
    s21::set<int> st3;
    std::set<int> st4;

    st.swap(st3);
    st2.swap(st4);

    ASSERT_EQ(st.empty(), st2.empty());

    auto it1 = st3.begin();
    auto it2 = st4.begin();

    for (; it1 != st.end() && it2 != st2.end(); ++it1, ++it2)
    {
        ASSERT_EQ(*it1, *it2);
    }
}
