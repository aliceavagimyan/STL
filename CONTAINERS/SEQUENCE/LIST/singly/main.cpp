#include "list.hpp"
int main()
{
    List<int> list;
    list.push_back(10);
    list.push_back(18);
    list.push_back(7);
    list.push_back(110);
    list.push_back(1);

    list.reverse();
    list.print();
    int n = 2;
    std::cout << list.find_n_fromEnd(n) << std::endl;
    return 0;
}