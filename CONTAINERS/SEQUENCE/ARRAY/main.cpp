
#include "array.hpp"

int main() {
    Array<int, 5> arr;

    
    arr.fill(10);

    arr[0] = 1;
    arr[1] = 2;

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Element at index " << i << ": " << arr[i] << std::endl;
    }


    try {
        std::cout << "Element at index 5: " << arr.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }


    std::cout << "Array elements: ";
    arr.print();

    return 0;
}
