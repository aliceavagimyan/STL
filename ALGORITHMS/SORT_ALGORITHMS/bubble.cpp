#include <iostream>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    std::cout << "enter the size of the array" << std::endl;
    int n;
    std::cin >> n;
    int *array = new int[n];
    std::cout << "Input elements of the array" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> array[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted array:";
    bubbleSort(array, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}
