#include <iostream>

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(array, n);

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}
