#include <vector>
#include <map>
#include <bits/stl_function.h>
#include <string>
#ifndef QUICK_SORT
#define QUICK_SORT

#ifdef BENCHMARK_EN
#include <benchmark/benchmark.h>
template <class ForwardIt, class UnaryPredicate>
inline ForwardIt partition_impl(ForwardIt first, ForwardIt last, benchmark::UserCounters &counter, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last)
        return first;

    for (ForwardIt i = std::next(first); i != last; ++i)
    {
        counter["comparisions"] += 1;
        if (p(*i))
        {
            std::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}

template <class FwdIt, class Compare = std::less<>>
void quick_sort(FwdIt first, FwdIt last, benchmark::UserCounters &counter, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1)
        return;
    auto const pivot = *std::next(first, N / 2);
    auto const middle1 = partition_impl(first, last, counter, [=](auto const &elem)
                                        { return cmp(elem, pivot); });
    auto const middle2 = partition_impl(middle1, last, counter, [=](auto const &elem)
                                        { return !cmp(pivot, elem); });
    quick_sort(first, middle1, counter, cmp); // assert(std::is_sorted(first, middle1, cmp));
    quick_sort(middle2, last, counter, cmp);  // assert(std::is_sorted(middle2, last, cmp));
}
#endif

template <class ForwardIt, class UnaryPredicate>
inline ForwardIt partition_impl(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last)
        return first;

    for (ForwardIt i = std::next(first); i != last; ++i)
    {
        if (p(*i))
        {
            std::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}

template <class FwdIt, class Compare = std::less<>>
void quick_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1)
        return;
    auto const pivot = *std::next(first, N / 2);
    auto const middle1 = partition_impl(first, last, [=](auto const &elem)
                                        { return cmp(elem, pivot); });
    auto const middle2 = partition_impl(middle1, last, [=](auto const &elem)
                                        { return !cmp(pivot, elem); });
    quick_sort(first, middle1, cmp); // assert(std::is_sorted(first, middle1, cmp));
    quick_sort(middle2, last, cmp);  // assert(std::is_sorted(middle2, last, cmp));
}
#endif
