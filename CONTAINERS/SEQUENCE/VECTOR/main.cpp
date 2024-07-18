#include <iostream>
#include "vector.hpp"

int main()
{

    Vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "vector";
    vec.print();

    vec.push_back(6);
    std::cout << " push_back(6): ";
    vec.print();

    vec.push_front(0);
    std::cout << "push_front(0): ";
    vec.print();

    vec.pop_back();
    std::cout << "pop_back(): ";
    vec.print();

    vec.pop_front();
    std::cout << "pop_front(): ";
    vec.print();

    vec.insert(99, 2);
    std::cout << "After insert(99, 2): ";
    vec.print();
    return 0;
}
