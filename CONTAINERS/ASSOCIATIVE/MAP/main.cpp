#include "map.hpp"
#include <iostream>

int main() {
    Map<int, std::string> map;

    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    if (map.find(2)) {
        std::cout << "Key 2 found with value: " << map[2] << std::endl;
    }

    map.erase(2);

    if (!map.find(2)) {
        std::cout << "Key 2 has been removed." << std::endl;
    }

    map.printInOrder();

    return 0;
}
