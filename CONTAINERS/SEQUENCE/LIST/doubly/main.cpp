#include <iostream>
#include "list.hpp"

int main() {
    DoublyList<int> list;

   
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    std::cout << "List after push_front and push_back operations: ";
    list.print();

   
    list.pop_front();
    list.pop_back();

    std::cout << "List after pop_front and pop_back operations: ";
    list.print();

   
    list.insert(25, 1); 
    list.insert(35, 2); 

    std::cout << "List after insert operations: ";
    list.print();

    return 0;
}
