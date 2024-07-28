#ifndef UNORDERED_MULTIMAP_HPP
#define UNORDERED_MULTIMAP_HPP

#include "hash.hpp"
#include <vector>
#include <iostream>

template<typename Key, typename Value>
class UnorderedMultimap : public Hash<Key, Value> {
public:
    UnorderedMultimap(int size) : Hash<Key, Value>(size) {}

    void insert(const Key& key, const Value& value) {
        Hash<Key, Value>::insert(key, value);
    }

    std::vector<Value> find(const Key& key) const {
        auto nodes = Hash<Key, Value>::search(key);
        std::vector<Value> values;
        for (const auto& node : nodes) {
            values.push_back(node->val);
        }
        return values;
    }

    void erase(const Key& key) {
        int index = Hash<Key, Value>::hashFunction(key);
        auto& bucket = Hash<Key, Value>::arr[index];

        for (auto it = bucket.begin(); it != bucket.end(); ) {
            if ((*it)->key == key) {
                delete *it;
                it = bucket.erase(it);
                Hash<Key, Value>::numElements--;
            } else {
                ++it;
            }
        }
    }

    int size() const {
        return Hash<Key, Value>::size();
    }

    void print() const {
        for (int i = 0; i < Hash<Key, Value>::capacity; ++i) {
            for (const auto& node : Hash<Key, Value>::arr[i]) {
                std::cout << "(" << node->key << ", " << node->val << ") ";
            }
        }
        std::cout << std::endl;
    }
};

#endif // UNORDERED_MULTIMAP_HPP
