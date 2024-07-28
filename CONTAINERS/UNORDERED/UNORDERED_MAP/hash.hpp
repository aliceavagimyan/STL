#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional> 
template<typename Key, typename Value>
struct Node {
    Key key;
    Value val;
    Node* next;

    Node(Key k, Value v) : key(k), val(v), next(nullptr) {}
};

template<typename Key, typename Value>
class Hash {
protected:
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
        Node<Key, Value>* newNode = new Node<Key, Value>(key, val);
        arr[index].push_back(newNode);
        ++numElements;
    }

    std::list<Node<Key, Value>*> search(Key key) const {
        int index = hashFunction(key);
        std::list<Node<Key, Value>*> result;
        for (auto node : arr[index]) {
            if (node->key == key) {
                result.push_back(node);
            }
        }
        return result;
    }

    int size() const {
        return numElements;
    }
};

#endif // HASH_HPP
