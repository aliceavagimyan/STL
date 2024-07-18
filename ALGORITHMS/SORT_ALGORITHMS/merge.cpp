#include <iostream>

void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    for (int i = 0; i < n1; ++i)
    {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            ++i;
        }
        else
        {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }

    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(array, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}
