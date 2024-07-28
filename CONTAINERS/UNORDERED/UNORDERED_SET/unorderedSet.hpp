#ifndef UNORDERED_SET_HPP
#define UNORDERED_SET_HPP

#include "hash.hpp"

template<typename Key>
class UnorderedSet : public Hash<Key, bool> {
public:
    UnorderedSet(int size) : Hash<Key, bool>(size) {}

    
    void insert(const Key& key) {
        Hash<Key, bool>::insert(key, true);
    }

    
    bool contains(const Key& key) const {
        return Hash<Key, bool>::search(key);
    }

   
    void erase(const Key& key) {
        int index = Hash<Key, bool>::hashFunction(key);
        auto& bucket = Hash<Key, bool>::arr[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if ((*it)->key == key) {
                delete *it;
                bucket.erase(it);
                Hash<Key, bool>::numElements--;
                return;
            }
        }
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

#endif // UNORDERED_SET_HPP
