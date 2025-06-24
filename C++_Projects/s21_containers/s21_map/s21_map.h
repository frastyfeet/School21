#ifndef S21_MAP_H
#define S21_MAP_H

#include <iterator>

#include "../s21_tree/s21_tree.h"

namespace s21
{
    template <typename Key, typename T>
    class map
    {
    public:
        using value_type = std::pair<const Key, T>;
        using key_type = Key;
        using mapped_type = T;
        using iterator = typename RBtree<value_type>::TreeIterator;
        using size_type = std::size_t;
        using reference = value_type &;
        using const_reference = const value_type &;

        map() = default;
        map(std::initializer_list<value_type> &items)
        {
        }

        std::pair<iterator, bool> insert(const value_type &value)
        {
            auto result = tree.insert(value);
            bool inserted = (result != nullptr);
            return {iterator(result), inserted};
        }

        T &at(const Key &key);

        iterator find(const Key &key);

    private:
        RBtree<value_type> tree;
    };

} // namespace s21

#endif