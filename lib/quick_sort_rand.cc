#include <vector>
#include <random>
#include "quick_sort.cc"

#ifndef RANDOMIZED_QUICK_SORT
#define RANDOMIZED_QUICK_SORT
template <typename T>
int partition_r(std::vector<T> v, int low, int high, std::mt19937 generator)
{
    // Generate a random number in between
    // low .. high
    auto rand = generator();
    int random = low + rand % (high - low);

    // Swap A[random] with A[high]
    std::swap(v[random], v[high]);

    return partition<T>(v, low, high);
}

/* The main function that implements QuickSort
  v --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template <typename T>
void _rqsort(std::vector<T> v, int low, int high, std::mt19937 generator)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition_r(v, low, high, generator);

        // Separately sort elements before
        // partition and after partition
        _rqsort<T>(v, low, pi - 1, generator);
        _rqsort<T>(v, pi + 1, high, generator);
    }
}

template <typename T>
void quick_sort_rand(std::vector<T> v, std::mt19937 generator)
{
    _rqsort<T>(v, 0, v.size() - 1, generator);
}
#endif