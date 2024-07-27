#include <iostream>
#include "multiset.hpp"

int main() {
    Multiset<int> multiset;

    
    multiset.insert(10);
    multiset.insert(20);
    multiset.insert(10);
    multiset.insert(30);
    multiset.insert(20);
    multiset.insert(10);

   
    std::cout << "Multiset elements in order:" << std::endl;
    multiset.printInOrder();


    std::cout << "Count of 10: " << multiset.count(10) << std::endl;
    std::cout << "Count of 20: " << multiset.count(20) << std::endl;
    std::cout << "Count of 30: " << multiset.count(30) << std::endl;
    std::cout << "Count of 40: " << multiset.count(40) << std::endl;

    
    multiset.remove(10);
    std::cout << "After removing one 10:" << std::endl;
    multiset.printInOrder();

    multiset.remove(10);
    std::cout << "After removing another 10:" << std::endl;
    multiset.printInOrder();

    multiset.remove(20);
    std::cout << "After removing one 20:" << std::endl;
    multiset.printInOrder();


    if (multiset.count(10) == 0 && multiset.count(20) == 0 && multiset.count(30) == 0) {
        std::cout << "Multiset is empty" << std::endl;
    } else {
        std::cout << "Multiset is not empty" << std::endl;
    }

    return 0;
}
