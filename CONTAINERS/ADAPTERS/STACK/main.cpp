
#include <iostream>
#include "stackWithList.hpp"

int main() {

    Stack<int> stack;

    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    
    std::cout << "Stack elements:" << std::endl;
    stack.print();

    
    std::cout << "Top element: " << stack.top() << std::endl;

   
    stack.pop();
    std::cout << "After pop, stack elements:" << std::endl;
    stack.print();

    
    std::cout << "Stack size: " << stack.size() << std::endl;

    
    if (stack.empty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is not empty" << std::endl;
    }

    try {
        while (!stack.empty()) {
            stack.pop();
        }
        stack.top(); 
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
