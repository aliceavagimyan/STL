#include <iostream>
#include "unorderedSet.hpp"

int main()
{

    UnorderedSet<int> mySet(10);

    mySet.insert(15);
    mySet.insert(20);
    mySet.insert(5);

    std::cout << "Contains 5: " << mySet.contains(5) << std::endl;
    std::cout << "Contains 10: " << mySet.contains(10) << std::endl;
    std::cout << "Contains 15: " << mySet.contains(15) << std::endl;

    mySet.erase(20);

    std::cout << "size: " << mySet.size() << std::endl;

    std::cout << "Elements of unordered set ";
    mySet.print();

    return 0;
}
