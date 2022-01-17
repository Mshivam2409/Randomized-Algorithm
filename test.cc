#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "lib/quick_sort.cc"
#include "lib/quick_sort_rand.cc"
#include "lib/merge_sort.cc"

TEST(SortingTest, MergeSort)
{
    std::vector<long double> v(10);
    std::iota(v.begin(), v.end(), 0);
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
    merge_sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; ++i)
    {
        ASSERT_LE(v[i], v[i + 1]);
    }
}

TEST(SortingTest, QuickSort)
{
    std::vector<long double> v(10);
    std::iota(v.begin(), v.end(), 0);
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
    quick_sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; ++i)
    {
        ASSERT_LE(v[i], v[i + 1]);
    }
}

TEST(SortingTest, QuickSortRand)
{
    std::vector<long double> v(10);
    std::iota(v.begin(), v.end(), 0);
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
    quick_sort_rand(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; ++i)
    {
        ASSERT_LE(v[i], v[i + 1]);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}