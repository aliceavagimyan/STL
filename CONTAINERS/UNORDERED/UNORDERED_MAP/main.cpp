#include <iostream>
#include "unorderedMap.hpp"

int main() {
    UnorderedMap<int, std::string> myMap(10);

    myMap.insert(1, "one");
    myMap.insert(2, "two");
    myMap.insert(3, "three");

    std::string* value = myMap.find(2);
    if (value) {
        std::cout << "Found key 2 with value: " << *value << std::endl;
    } else {
        std::cout << "Key 2 not found" << std::endl;
    }

    myMap.erase(2);

    value = myMap.find(2);
    if (value) {
        std::cout << "Found key 2 with value: " << *value << std::endl;
    } else {
        std::cout << "Key 2 not found" << std::endl;
    }

    std::cout << "Size: " << myMap.size() << std::endl;

    std::cout << "Elements of unordered map: ";
    myMap.print();

    return 0;
}
