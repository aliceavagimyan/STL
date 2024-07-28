#include <iostream>
#include "unorderedMultiSet.hpp"

int main() {
    UnorderedMultiset<int> myMultiset(10);

    myMultiset.insert(15);
    myMultiset.insert(20);
    myMultiset.insert(5);
    myMultiset.insert(15);
    myMultiset.insert(20);
    myMultiset.insert(5);

    std::cout << "Contains 5: " << myMultiset.contains(5) << std::endl;
    std::cout << "Contains 10: " << myMultiset.contains(10) << std::endl;
    std::cout << "Contains 15: " << myMultiset.contains(15) << std::endl;

    std::cout << "Count of 5: " << myMultiset.count(5) << std::endl;
    std::cout << "Count of 15: " << myMultiset.count(15) << std::endl;

    myMultiset.erase(20);

    std::cout << "Size: " << myMultiset.size() << std::endl;

    std::cout << "Elements of unordered multiset: ";
    myMultiset.print();

    return 0;
}
