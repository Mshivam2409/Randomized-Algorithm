#include <vector>
#include <iterator>
#include <algorithm>

#ifndef MERGE_SORT
#define MERGE_SORT

#ifdef BENCHMARK_EN
#include <benchmark/benchmark.h>
template <class BiDirIt, class Compare = std::less<>>
void merge_sort(BiDirIt first, BiDirIt last, benchmark::UserCounters &counter, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1)
        return;
    auto const middle = std::next(first, N / 2);
    merge_sort(first, middle, counter, cmp);      // assert(std::is_sorted(first, middle, cmp));
    merge_sort(middle, last, counter, cmp);       // assert(std::is_sorted(middle, last, cmp));
    std::inplace_merge(first, middle, last, cmp); // assert(std::is_sorted(first, last, cmp));
    counter["comparisions"] += N - 1;             // assuming memory availabilty
}
#endif

template <class BiDirIt, class Compare = std::less<>>
void merge_sort(BiDirIt first, BiDirIt last, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1)
        return;
    auto const middle = std::next(first, N / 2);
    merge_sort(first, middle, cmp);               // assert(std::is_sorted(first, middle, cmp));
    merge_sort(middle, last, cmp);                // assert(std::is_sorted(middle, last, cmp));
    std::inplace_merge(first, middle, last, cmp); // assert(std::is_sorted(first, last, cmp));
}
#endif
