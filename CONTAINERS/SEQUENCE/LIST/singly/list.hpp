#ifndef LIST
#define LIST
#include <iostream>
template <typename T>
class List
{
public:
    List();
    ~List();
    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void print();
    void reverse();
    T find_n_fromEnd(int n) const;
    void insert(T data, int position);
    bool hasCycle() const;
    T &operator[](int index);

    Node<T> *getHead() const
    {
        return head;
    }

private:
    template <typename U>
    class Node
    {
    public:
        U data;
        Node<U> *pNext;
        Node(U newData) : data(newData), pNext(nullptr) {}
    };

private:
    Node<T> *head;
};

#endif // LIST

template <typename T>
List<T>::List()
{
    head = nullptr;
}
template <typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        pop_front();
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
}
template <typename T>
void List<T>::push_front(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->pNext = head;
    head = newNode;
}
template <typename T>
void List<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
}
template <typename T>
void List<T>::insert(T data, int position)
{
    if (position == 0)
    {
        push_front(data);
        return;
    }

    Node<T> *current = head;
    size_t currentIndex = 0;

    while (current != nullptr && currentIndex < position - 1)
    {
        current = current->pNext;
        currentIndex++;
    }

    if (current == nullptr)
    {
        return;
    }

    Node<T> *newNode = new Node<T>(data);
    newNode->pNext = current->pNext;
    current->pNext = newNode;
}
template <typename T>
void List<T>::print()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->pNext;
    }
    std::cout << std::endl;
}
template <typename T>
void List<T>::reverse()
{
    Node<T> *prev = nullptr;
    Node<T> *current = head;
    Node<T> *next = nullptr;

    while (current != nullptr)
    {
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
template <typename T>
T List<T>::find_n_fromEnd(int n) const
{
    if (head == nullptr || n <= 0)
    {
        return;
    }
    int length = 0;
    Node<T> *current = head;
    while (current != nullptr)
    {
        ++length;
        current = current->pNext;
    }

    int targetIndex = length - n;

    current = head;
    for (int i = 0; i < targetIndex; ++i)
    {
        current = current->pNext;
    }

    return current->data;
}
template <typename T>
bool List<T>::hasCycle() const
{
    if (!head)
    {
        return false;
    }

    Node<T> *slowPtr = head;
    Node<T> *fastPtr = head;

    while (fastPtr && fastPtr->pNext)
    {
        slowPtr = slowPtr->pNext;
        fastPtr = fastPtr->pNext->pNext;

        if (slowPtr == fastPtr)
        {
            return true;
        }
    }

    return false;
}
template <typename T>
T &List<T>::operator[](int index)
{
    if (index < 0)
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; ++i)
    {
        if (current == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }
        current = current->pNext;
    }

    if (current == nullptr)
    {
        throw std::out_of_range("Index out of range");
    }

    return current->data;
}