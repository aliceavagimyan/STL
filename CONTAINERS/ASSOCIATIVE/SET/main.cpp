#include <iostream>
#include "set.hpp"

int main() {
    Set<int> mySet;

    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(3);
    mySet.insert(8);

    
    std::cout << "Set contents in order: ";
    mySet.printInOrder(); 

    std::cout << "Contains 5: " << (mySet.contains(5) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 7: " << (mySet.contains(7) ? "Yes" : "No") << std::endl; 
    
    mySet.insert(5); 

    std::cout << "Set contents after attempting to insert a duplicate: ";
    mySet.printInOrder(); 

    mySet.remove(3);
    mySet.remove(10);

    std::cout << "Set contents after removing 3 and 10: ";
    mySet.printInOrder(); 
    return 0;
}
