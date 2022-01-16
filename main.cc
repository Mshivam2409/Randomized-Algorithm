#include <benchmark/benchmark.h>
#include <random>
#include "lib/quick_sort.cc"
#include "lib/quick_sort_rand.cc"
// Define size
#ifndef SIZE
#define SIZE 100
#endif
#define ITERATIONS 500

static void BM_QuickSort(benchmark::State &state)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<long double> distr(0, 1LL);
    std::vector<long double> v;
    for (int i = 1; i <= SIZE; i++)
        v.push_back(distr(generator));

    for (auto _ : state)
        quick_sort<long double>(v);
}
// Register the function as a benchmark
BENCHMARK(BM_QuickSort)->Iterations(ITERATIONS);

static void BM_QuickSortRandom(benchmark::State &state)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<long double> distr(0, 1LL);
    std::vector<long double> v;
    for (int i = 1; i <= SIZE; i++)
        v.push_back(distr(generator));

    for (auto _ : state)
        quick_sort_rand<long double>(v, generator);
}
// Register the function as a benchmark
BENCHMARK(BM_QuickSortRandom)->Iterations(ITERATIONS);

BENCHMARK_MAIN();