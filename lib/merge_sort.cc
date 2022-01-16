#include <vector>
#include <iterator>
#include <algorithm>

#ifndef MERGE_SORT
#define MERGE_SORT
template <typename RandomAccessIterator1, typename RandomAccessIterator2>
void merge_sort_impl(RandomAccessIterator1 source_begin,
                     RandomAccessIterator1 source_end,
                     RandomAccessIterator2 target_begin,
                     RandomAccessIterator2 target_end)
{
    auto range_length = std::distance(source_begin, source_end);

    if (range_length < 2)
    {
        return;
    }

    auto left_chunk_length = range_length >> 1;
    auto source_left_chunk_end = source_begin;
    auto target_left_chunk_end = target_begin;

    std::advance(source_left_chunk_end, left_chunk_length);
    std::advance(target_left_chunk_end, left_chunk_length);

    merge_sort_impl(target_begin,
                    target_left_chunk_end,
                    source_begin,
                    source_left_chunk_end);

    merge_sort_impl(target_left_chunk_end,
                    target_end,
                    source_left_chunk_end,
                    source_end);

    std::merge(source_begin,
               source_left_chunk_end,
               source_left_chunk_end,
               source_end,
               target_begin);
}

template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator begin, RandomAccessIterator end)
{
    auto range_length = std::distance(begin, end);

    if (range_length < 2)
    {
        return;
    }

    using value_type = typename std::iterator_traits<RandomAccessIterator>::value_type;
    std::vector<value_type> aux(begin, end);
    merge_sort_impl(aux.begin(), aux.end(), begin, end);
}
#endif