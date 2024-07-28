#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename Key, typename Value>
struct Node {
    Key key;
    Value val;
    Node* next;

    Node(Key k, Value v) : key(k), val(v), next(nullptr) {}
};

template<typename Key, typename Value>
class Hash {
private:
    int capacity;
    int numElements;
    std::vector<std::list<Node<Key, Value>*>> arr;

    int hashFunction(Key key) const {
        return std::hash<Key>()(key) % capacity;
    }

public:
    Hash(const int& size) : capacity(size), numElements(0), arr(size) {}

    ~Hash() {
        for (int i = 0; i < capacity; ++i) {
            for (auto it = arr[i].begin(); it != arr[i].end(); ++it) {
                delete *it;
            }
            arr[i].clear(); 
        }
    }

    void insert(Key key, Value val) {
        int index = hashFunction(key);
        for (auto node : arr[index]) {
            if (node->key == key) {
                node->val = val;
                return;
            }
        }
        
        Node<Key, Value>* newNode = new Node<Key, Value>(key, val);
        arr[index].push_back(newNode);
        ++numElements;
    }

    Value search(Key key) const {
        int index = hashFunction(key);
        for (auto node : arr[index]) {
            if (node->key == key) {
                return node->val; 
            }
        }
        std::cout << "Key '" << key << "' not found in hash map" << std::endl;
      
    }

    int size() const {
        return numElements;
    }
};

#endif // HASH_HPP
