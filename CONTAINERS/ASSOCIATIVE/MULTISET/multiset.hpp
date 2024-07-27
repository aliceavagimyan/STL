#ifndef MULTISET_HPP
#define MULTISET_HPP

#include "bst.hpp"

template <typename T>
class Multiset : public BST<T> {
public:
    void insert(const T& value);
    void remove(const T& value);
    int count(const T& value) const;
    void printInOrder() const;

private:
    struct Node : public BST<T>::Node {
        int count;
        Node(const T& value) : BST<T>::Node(value), count(1) {}
    };

    void printInOrder(typename BST<T>::Node* node) const;
    void clear(typename BST<T>::Node* node);
};

template <typename T>
void Multiset<T>::insert(const T& value) {
    typename BST<T>::Node** current = &this->root;
    while (*current) {
        if (value == (*current)->data) {
            static_cast<Node*>(*current)->count++;
            return;
        } else if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    *current = new Node(value);
}

template <typename T>
void Multiset<T>::remove(const T& value) {
    typename BST<T>::Node** current = &this->root;

    while (*current && (*current)->data != value) {
        if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }

    if (*current) {
        Node* nodeToDelete = static_cast<Node*>(*current);

        if (nodeToDelete->count > 1) {
            nodeToDelete->count--;
            return;
        }

        if (!(*current)->left) {
            *current = (*current)->right;
        } else if (!(*current)->right) {
            *current = (*current)->left;
        } else {
            typename BST<T>::Node** successor = &((*current)->right);
            while ((*successor)->left) {
                successor = &((*successor)->left);
            }
            (*current)->data = (*successor)->data;
            nodeToDelete = static_cast<Node*>(*successor);
            *successor = (*successor)->right;
        }
        delete nodeToDelete;
    }
}

template <typename T>
int Multiset<T>::count(const T& value) const {
    typename BST<T>::Node* current = this->root;
    while (current) {
        if (value == current->data) {
            return static_cast<Node*>(current)->count;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return 0;
}

template <typename T>
void Multiset<T>::printInOrder() const {
    printInOrder(this->root);
    std::cout << std::endl;
}

template <typename T>
void Multiset<T>::printInOrder(typename BST<T>::Node* node) const {
    if (node) {
        printInOrder(node->left);
        for (int i = 0; i < static_cast<Node*>(node)->count; ++i) {
            std::cout << node->data << " ";
        }
        printInOrder(node->right);
    }
}

#endif // MULTISET_HPP