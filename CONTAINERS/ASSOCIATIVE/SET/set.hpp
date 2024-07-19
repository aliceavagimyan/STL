#ifndef SET_HPP
#define SET_HPP

#include "bst.hpp"
template <typename T>
class Set : public BST<T> {
public:
    using BST<T>::BST;
    void insert(const T& value);
    bool contains(const T& value) const;
};

template <typename T>
void Set<T>::insert(const T& value) {
  
    if (!this->find(value)) {
        BST<T>::insert(value); 
    }
}


template <typename T>
bool Set<T>::contains(const T& value) const {
    return this->find(value);
}

#endif // SET_HPP
