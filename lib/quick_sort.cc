#include <vector>

#ifndef QUICK_SORT
#define QUICK_SORT
template <typename T>
int partition(std::vector<T> arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
  v --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template <typename T>
void _qsort(std::vector<T> v, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(v, low, high);

        // Separately sort elements before
        // partition and after partition
        _qsort<T>(v, low, pi - 1);
        _qsort<T>(v, pi + 1, high);
    }
}

template <typename T>
void quick_sort(std::vector<T> v)
{
    _qsort<T>(v, 0, v.size() - 1);
}
#endif