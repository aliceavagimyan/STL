#ifndef MAP_HPP
#define MAP_HPP

#include "bst.hpp"
#include <utility> // std::pair

template <typename Key, typename Value>
class Map : public BST<std::pair<Key, Value>> {
public:
    void insert(const Key& key, const Value& value);
    bool find(const Key& key) const;
    Value& operator[](const Key& key);
    void erase(const Key& key);
    void printInOrder() const;

private:
    using typename BST<std::pair<Key, Value>>::Node;

    Node* findNode(Node* node, const Key& key) const;
    void printInOrder(Node* node) const;
};

#endif // MAP_HPP

template <typename Key, typename Value>
void Map<Key, Value>::insert(const Key& key, const Value& value) {
    std::pair<Key, Value> kvPair(key, value);
    BST<std::pair<Key, Value>>::insert(kvPair);
}

template <typename Key, typename Value>
bool Map<Key, Value>::find(const Key& key) const {
     if (find(key)) {
        std::cout << "Error" << std::endl;
        return;
    }
    Node* node = findNode(this->root, key);
    return node != nullptr;
}

template <typename Key, typename Value>
Value& Map<Key, Value>::operator[](const Key& key) {
    Node* node = findNode(this->root, key);
    if (node) {
        return node->data.second;
    }
   
    std::pair<Key, Value> kvPair(key, Value());
    this->insert(key, Value());
    node = findNode(this->root, key);
    return node->data.second;
}

template <typename Key, typename Value>
void Map<Key, Value>::erase(const Key& key) {
    Node** current = &this->root;
    Node* parent = nullptr;

    while (*current && (*current)->data.first != key) {
        parent = *current;
        if (key < (*current)->data.first) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }

    if (*current) {
        Node* nodeToDelete = *current;
        if ((*current)->right) {
            *current = (*current)->right;
        } else {
            *current = (*current)->left;
        }
        delete nodeToDelete;
    }
}

template <typename Key, typename Value>
typename Map<Key, Value>::Node* Map<Key, Value>::findNode(Node* node, const Key& key) const {
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
void Map<Key, Value>::printInOrder() const {
    printInOrder(this->root);
    std::cout << std::endl;
}

template <typename Key, typename Value>
void Map<Key, Value>::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << "(" << node->data.first << ", " << node->data.second << ") ";
        printInOrder(node->right);
    }
}
