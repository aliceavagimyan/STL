#ifndef MULTIMAP_HPP
#define MULTIMAP_HPP

#include "bst.hpp"
#include <utility> // std::pair
#include <iostream>

template <typename Key, typename Value>
class MultiMap : public BST<std::pair<Key, Value>> {
public:
    void insert(const Key& key, const Value& value);
    bool find(const Key& key) const;
    Value& operator[](const Key& key);
    void erase(const Key& key);
    void printInOrder() const;

private:
    void erase(typename BST<std::pair<Key, Value>>::Node*& node, const Key& key);
    typename BST<std::pair<Key, Value>>::Node* findNode(typename BST<std::pair<Key, Value>>::Node* node, const Key& key) const;
    void printInOrder(typename BST<std::pair<Key, Value>>::Node* node) const;
};

#endif // MULTIMAP_HPP

template <typename Key, typename Value>
void MultiMap<Key, Value>::insert(const Key& key, const Value& value) {
    std::pair<Key, Value> kvPair(key, value);
    BST<std::pair<Key, Value>>::insert(kvPair);
}

template <typename Key, typename Value>
bool MultiMap<Key, Value>::find(const Key& key) const {
    return findNode(this->root, key) != nullptr;
}

template <typename Key, typename Value>
Value& MultiMap<Key, Value>::operator[](const Key& key) {
    typename BST<std::pair<Key, Value>>::Node* node = findNode(this->root, key);
    if (node) {
        return node->data.second;
    }

    std::pair<Key, Value> kvPair(key, Value());
    this->insert(key, Value());
    node = findNode(this->root, key);
    return node->data.second;
}

template <typename Key, typename Value>
void MultiMap<Key, Value>::erase(const Key& key) {
    erase(this->root, key);
}

template <typename Key, typename Value>
void MultiMap<Key, Value>::erase(typename BST<std::pair<Key, Value>>::Node*& node, const Key& key) {
    if (!node) return;

    if (key < node->data.first) {
        erase(node->left, key);
    } else if (key > node->data.first) {
        erase(node->right, key);
    } else {
    
        typename BST<std::pair<Key, Value>>::Node* oldNode = node;
        if (!node->left) {
            node = node->right;
        } else if (!node->right) {
            node = node->left;
        } else {
            typename BST<std::pair<Key, Value>>::Node* successor = node->right;
            while (successor->left) {
                successor = successor->left;
            }
            node->data = successor->data;
            erase(node->right, successor->data.first);
        }
        delete oldNode;
    }
}

template <typename Key, typename Value>
typename BST<std::pair<Key, Value>>::Node* MultiMap<Key, Value>::findNode(typename BST<std::pair<Key, Value>>::Node* node, const Key& key) const {
    while (node) {
        if (key == node->data.first) {
            return node;
        } else if (key < node->data.first) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return nullptr;
}

template <typename Key, typename Value>
void MultiMap<Key, Value>::printInOrder() const {
    printInOrder(this->root);
    std::cout << std::endl;
}

template <typename Key, typename Value>
void MultiMap<Key, Value>::printInOrder(typename BST<std::pair<Key, Value>>::Node* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << "(" << node->data.first << ", " << node->data.second << ") ";
        printInOrder(node->right);
    }
}

