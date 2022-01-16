#include <vector>
#include <random>

#ifndef RANDOMIZED_QUICK_SORT
#define RANDOMIZED_QUICK_SORT
template <typename T>
int partition(std::vector<T> &data, int begin, int end)
{
    // choose the pivot randomly
    swap(data[begin + int(double(rand()) / RAND_MAX * (end - begin + 1))], data[begin]);
    int p = begin, i = begin + 1, j = begin + 1;
    for (; j <= end; ++j)
    {
        if (data[j] <= data[p])
        {
            swap(data[i], data[j]);
            ++i;
        }
    }
    swap(data[p], data[--i]);
    return i;
}

template <typename T>
void _rqsort(std::vector<T> &data, int begin, int end)
{
    if (begin >= end || begin < 0)
    {
        return;
    }
    int p = partition(data, begin, end); // position of the last pivot
    _rqsort(data, begin, p - 1);
    _rqsort(data, p + 1, end);
}

template <typename T>
void quick_sort_rand(std::vector<T> v)
{
    _rqsort<T>(v, 0, v.size() - 1);
}
#endif