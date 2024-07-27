#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template <typename T>
class BST {
public:
    BST();
    ~BST();
    void insert(const T& value);
    bool find(const T& value) const;
    void remove(const T& value);
    void printInOrder() const;

protected:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    void printInOrder(Node* node) const;
    void clear(Node* node);
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear(root);
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
void BST<T>::insert(const T& value) {
    Node** current = &root;
    while (*current) {
        if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    *current = new Node(value);
}

template <typename T>
bool BST<T>::find(const T& value) const {
    Node* current = root;
    while (current) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

template <typename T>
void BST<T>::remove(const T& value) {
    Node** current = &root;
    Node* parent = nullptr;
    
    while (*current && (*current)->data != value) {
        parent = *current;
        if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    
    if (*current) {
        Node* nodeToDelete = *current;
        
        if (!(*current)->left) {
            *current = (*current)->right;
        } else if (!(*current)->right) {
            *current = (*current)->left;
        } else {
            Node** successor = &((*current)->right);
            while ((*successor)->left) {
                successor = &((*successor)->left);
            }
            (*current)->data = (*successor)->data;
            nodeToDelete = *successor;
            *successor = (*successor)->right;
        }
        delete nodeToDelete;
    }
}

template <typename T>
void BST<T>::printInOrder() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}
#endif // BST_HPP
