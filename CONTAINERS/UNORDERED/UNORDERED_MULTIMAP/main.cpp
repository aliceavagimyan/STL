#include <iostream>
#include "unorderedMultimap.hpp"

int main()
{

    UnorderedMultimap<int, std::string> myMap(10);

    myMap.insert(1, "apple");
    myMap.insert(1, "banana");
    myMap.insert(1, "cherry");

    myMap.insert(2, "orange");
    myMap.insert(3, "grape");
    myMap.insert(3, "lemon");

    auto values1 = myMap.find(1);
    std::cout << "Values for key 1: ";
    for (const auto &val : values1)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto values3 = myMap.find(3);
    std::cout << "Values for key 3: ";
    for (const auto &val : values3)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "All elements in the UnorderedMultimap: ";
    myMap.print();

    myMap.erase(1);

    std::cout << "All elements after erasing key 1: ";
    myMap.print();

    std::cout << "Size of the UnorderedMultimap: " << myMap.size() << std::endl;

    return 0;
}
