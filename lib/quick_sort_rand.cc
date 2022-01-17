#include <vector>
#include <random>

#ifndef RANDOMIZED_QUICK_SORT
#define RANDOMIZED_QUICK_SORT
#ifdef BENCHMARK_EN
#include <benchmark/benchmark.h>
template <typename T>
int random_partition(std::vector<T> &data, int begin, int end, benchmark::UserCounters &counter)
{
    // choose the pivot randomly
    std::swap(data[begin + int(double(rand()) / RAND_MAX * (end - begin + 1))], data[begin]);
    int p = begin, i = begin + 1, j = begin + 1;
    for (; j <= end; ++j)
    {
        counter["comparisions"]++;
        if (data[j] <= data[p])
        {
            std::swap(data[i], data[j]);
            ++i;
        }
    }
    std::swap(data[p], data[--i]);
    return i;
}

template <typename T>
void quick_sort_rand_impl(std::vector<T> &data, int begin, int end, benchmark::UserCounters &counter)
{
    if (begin >= end || begin < 0)
    {
        return;
    }
    int p = random_partition(data, begin, end, counter); // position of the last pivot
    quick_sort_rand_impl(data, begin, p - 1, counter);
    quick_sort_rand_impl(data, p + 1, end, counter);
}

template <typename T>
void quick_sort_rand(std::vector<T> &v, benchmark::UserCounters &counter)
{
    quick_sort_rand_impl<T>(v, 0, v.size() - 1, counter);
}
#endif

template <typename T>
int random_partition(std::vector<T> &data, int begin, int end)
{
    // choose the pivot randomly
    std::swap(data[begin + int(double(rand()) / RAND_MAX * (end - begin + 1))], data[begin]);
    int p = begin, i = begin + 1, j = begin + 1;
    for (; j <= end; ++j)
    {
        if (data[j] <= data[p])
        {
            std::swap(data[i], data[j]);
            ++i;
        }
    }
    std::swap(data[p], data[--i]);
    return i;
}

template <typename T>
void quick_sort_rand_impl(std::vector<T> &data, int begin, int end)
{
    if (begin >= end || begin < 0)
    {
        return;
    }
    int p = random_partition(data, begin, end); // position of the last pivot
    quick_sort_rand_impl(data, begin, p - 1);
    quick_sort_rand_impl(data, p + 1, end);
}

template <typename T>
void quick_sort_rand(std::vector<T> &v)
{
    quick_sort_rand_impl<T>(v, 0, v.size() - 1);
}
#endif