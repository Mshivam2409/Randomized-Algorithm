#include <vector>
#include <map>
#include <string>
#ifndef QUICK_SORT
#define QUICK_SORT

#ifdef BENCHMARK_EN
template <typename Iter>
#include <benchmark/benchmark.h>
inline Iter partition(const Iter &beg, const Iter &end, benchmark::UserCounters &counter)
{
    assert(beg != end);
    auto piv = std::prev(end);
    auto index_small = beg;

    for (auto index_large = beg; index_large != piv; ++index_large)
    {
        counter["comparisions"]++;
        if (*index_large <= *piv)
        {
            std::swap(*index_large, *index_small);
            std::advance(index_small, 1);
        }
    }
    std::swap(*index_small, *piv);
    return index_small;
}

template <typename Iter>
void quick_sort(const Iter &beg, const Iter &end, benchmark::UserCounters &counter)
{
    if (std::distance(beg, end) > 1)
    {
        const auto &piv = partition(beg, end, counter);
        quick_sort(beg, piv, counter);
        quick_sort(piv, end, counter);
    }
}
#endif

template <typename Iter>
inline Iter partition(const Iter &beg, const Iter &end)
{
    assert(beg != end);
    auto piv = std::prev(end);
    auto index_small = beg;

    for (auto index_large = beg; index_large != piv; ++index_large)
    {
        if (*index_large <= *piv)
        {
            std::swap(*index_large, *index_small);
            std::advance(index_small, 1);
        }
    }
    std::swap(*index_small, *piv);
    return index_small;
}

template <typename Iter>
void quick_sort(const Iter &beg, const Iter &end)
{
    if (std::distance(beg, end) > 1)
    {
        const auto &piv = partition(beg, end);
        quick_sort(beg, piv);
        quick_sort(piv, end);
    }
}
#endif
