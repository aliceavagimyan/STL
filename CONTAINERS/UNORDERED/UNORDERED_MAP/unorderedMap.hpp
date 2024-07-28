#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include "hash.hpp"
#include <iostream>

template<typename Key, typename Value>
class UnorderedMap : public Hash<Key, Value> {
public:
    UnorderedMap(int size) : Hash<Key, Value>(size) {}

    void insert(const Key& key, const Value& value) {
        Hash<Key, Value>::insert(key, value);
    }

    Value* find(const Key& key) const {
        auto nodes = Hash<Key, Value>::search(key);
        if (!nodes.empty()) {
            return &(nodes.front()->val); 
        }
        return nullptr;
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

#endif // UNORDERED_MAP_HPP
