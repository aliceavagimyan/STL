#include <iostream>
#include "bst.hpp"

int main() {
    BST<int> tree;
    
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);

    std::cout << "In-order traversal: ";
    tree.printInOrder();

    std::cout << "Find 4: " << (tree.find(4) ? "Found" : "Not Found") << std::endl;
    std::cout << "Find 10: " << (tree.find(10) ? "Found" : "Not Found") << std::endl;

    tree.remove(7);
    std::cout << "After removing 7: ";
    tree.printInOrder();

    return 0;
}
