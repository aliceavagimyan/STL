#ifndef STACK_HPP
#define STACK_HPP

#include "list.hpp"

template <typename T>
class Stack : private List<T> {
public:
    void push(const T& data) {
        this->push_front(data);
    }

    void pop() {
        if (this->empty()) {
            std::cout << "Stack empty" << std::endl;
        } else {
            this->pop_front();
        }
    }

    bool empty() const {
        return List<T>::empty();
    }

    T top() const {
        return List<T>::top();
    }

    int size() const {
        int count = 0;
        typename List<T>::template Node<T>* current = this->head;
        while (current != nullptr) {
            ++count;
            current = current->pNext;
        }
        return count;
    }

    void print() const {
        List<T>::print();
    }
};

#endif // STACK_HPP
