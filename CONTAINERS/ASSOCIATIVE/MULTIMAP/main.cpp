#include <iostream>
#include "multimap.hpp"

int main() {
    
    MultiMap<int, std::string> multiMap;
    multiMap.insert(1, "apple");
    multiMap.insert(2, "banana");
    multiMap.insert(1, "apricot");
    multiMap.insert(3, "cherry");
    multiMap.insert(2, "blueberry");


    std::cout << "MultiMap in order:" << std::endl;
    multiMap.printInOrder();

 
    std::cout << "Finding key 2: " << (multiMap.find(2) ? "Found" : "Not Found") << std::endl;
    std::cout << "Finding key 4: " << (multiMap.find(4) ? "Found" : "Not Found") << std::endl;
    
    std::cout << "Value for key 1: " << multiMap[1] << std::endl;

    std::cout << "Removing key 2..." << std::endl;
    multiMap.erase(2);


    std::cout << "MultiMap in order after removal:" << std::endl;
    multiMap.printInOrder();

    return 0;
}
