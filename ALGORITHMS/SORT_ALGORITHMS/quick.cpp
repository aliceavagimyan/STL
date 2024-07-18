#include <iostream>

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
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
    quickSort(array, 0, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }
    return 0;
}
