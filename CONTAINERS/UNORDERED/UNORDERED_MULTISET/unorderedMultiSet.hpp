#ifndef UNORDERED_MULTISET_HPP
#define UNORDERED_MULTISET_HPP

#include "hash.hpp"

template<typename Key>
class UnorderedMultiset : public Hash<Key, bool> {
public:
    UnorderedMultiset(int size) : Hash<Key, bool>(size) {}

    void insert(const Key& key) {
        Hash<Key, bool>::insert(key, true);
    }

    bool contains(const Key& key) const {
        auto nodes = Hash<Key, bool>::search(key);
        return !nodes.empty();
    }

    void erase(const Key& key) {
        int index = Hash<Key, bool>::hashFunction(key);
        auto& bucket = Hash<Key, bool>::arr[index];

        for (auto it = bucket.begin(); it != bucket.end(); ) {
            if ((*it)->key == key) {
                delete *it;
                it = bucket.erase(it);
                Hash<Key, bool>::numElements--;
            } else {
                ++it;
            }
        }
    }

    int count(const Key& key) const {
        auto nodes = Hash<Key, bool>::search(key);
        return nodes.size();
    }

    int size() const {
        return Hash<Key, bool>::size();
    }

    void print() const {
        for (int i = 0; i < Hash<Key, bool>::capacity; ++i) {
            for (const auto& node : Hash<Key, bool>::arr[i]) {
                std::cout << node->key << " ";
            }
        }
        std::cout << std::endl;
    }
};

#endif // UNORDERED_MULTISET_HPP
