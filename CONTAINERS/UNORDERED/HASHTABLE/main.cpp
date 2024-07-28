#include "hash.hpp"
int main(){
    Hash<std::string ,int> products(100);
    products.insert("Laptop", 1500.0);
    products.insert("Smartphone", 800.0);
    products.insert("Tablet", 500.0);
    products.insert("Monitor", 300.0);
    products.insert("Keyboard", 100.0);

    std::cout << "Price for 'Monitor': $" << products.search("Monitor") << std::endl;
    std::cout << "Price for 'Laptop': $" << products.search("Laptop") << std::endl;
    std::cout << "Price for 'Smartphone': $" << products.search("Smartphone") << std::endl;
    std::cout << "Price for 'Keyboard': $" << products.search("Keyboard") << std::endl;
    return 0;
}