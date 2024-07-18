#ifndef _INPUT_ITERATOR_
#define _INPUT_ITERATOR_

#include <iostream>

template <typename T>
class Node {
public:
    Node* pNext;
    T data;
    Node(const T& newData) : data(newData), pNext(nullptr) {}
};

template <typename T>
class InputIterator {
public:
    Node<T>* ptr;

    InputIterator(Node<T>* nodePtr) : ptr(nodePtr) {}

    T& operator*() const {
        return ptr->data;
    }
    T* operator->() const {
        return &(ptr->data);
    }

    InputIterator& operator++() {
        ptr = ptr->pNext;
        return *this;
    }

    InputIterator operator++(int) {
        InputIterator temp = *this;
        ptr = ptr->pNext;
        return temp;
    }

    bool operator==(const InputIterator& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const InputIterator& other) const {
        return !(*this == other);
    }
};

template <typename T>
class List {
public:
    List();
    ~List();
    void push_front(T data);
    void pop_front();
    void print() const;
    InputIterator<T> begin() const {
        return InputIterator<T>(head);
    }
    InputIterator<T> end() const {
        return InputIterator<T>(nullptr);
    }

private:
    Node<T>* head;
};

template<typename T>
List<T>::List() {
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    while (head != nullptr) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->pNext = head;
    head = newNode;
}

template<typename T>
void List<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
}

template<typename T>
void List<T>::print() const {
    for (InputIterator<T> it = begin(); it != end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif //_INPUT_ITERATOR_