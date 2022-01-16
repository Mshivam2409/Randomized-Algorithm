#include <benchmark/benchmark.h>
#include <random>
#include "lib/quick_sort.cc"
#include "lib/quick_sort_rand.cc"
#include "lib/merge_sort.cc"
// Define size
#ifndef SIZE
#define SIZE 100
#endif
#ifdef OVERRIDE_ITERATIONS
#define ITERATIONS 500
#endif

static void BM_QuickSort(benchmark::State &state)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<long double> distr(0, 1LL);
    std::vector<long double> v;
    for (int i = 1; i <= SIZE; i++)
        v.push_back(distr(generator));

    state.counters.insert({"comparisions", 0});

    for (auto _ : state)
        quick_sort<long double>(v);
}
// Register the function as a benchmark
#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_QuickSort)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_QuickSort);
#endif

static void BM_QuickSortRandom(benchmark::State &state)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<long double> distr(0, 1LL);
    std::vector<long double> v;
    for (int i = 1; i <= SIZE; i++)
        v.push_back(distr(generator));

    for (auto _ : state)
        quick_sort_rand<long double>(v);
}
// Register the function as a benchmark
#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_QuickSortRandom)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_QuickSortRandom);
#endif

static void BM_MergeSort(benchmark::State &state)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<long double> distr(0, 1LL);
    std::vector<long double> v;
    for (int i = 1; i <= SIZE; i++)
        v.push_back(distr(generator));

    for (auto _ : state)
        merge_sort(v.begin(), v.end());
}

#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_MergeSort)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_MergeSort);
#endif

BENCHMARK_MAIN();