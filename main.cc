#include <benchmark/benchmark.h>
#include <random>
#include "lib/quick_sort.cc"
#include "lib/quick_sort_rand.cc"
#include "lib/merge_sort.cc"
#include "lib/sample.cc"
// Define size
#ifndef SIZE
#define SIZE 100
#endif
#ifdef OVERRIDE_ITERATIONS
#ifndef ITERATIONS
#define ITERATIONS 500
#endif
#endif

static void BM_QuickSort(benchmark::State &state)
{
    state.counters.insert({"comparisions", 0});

    for (auto _ : state)
    {
        state.PauseTiming();
        auto seed = state.iterations();
        auto v = generate_vector<long double>(SIZE, seed, 0, 1);
        state.ResumeTiming();
        quick_sort(v.begin(), v.end(), state.counters);
    }
}
// Register the function as a benchmark
#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_QuickSort)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_QuickSort);
#endif

static void BM_QuickSortRandom(benchmark::State &state)
{
    state.counters.insert({"comparisions", 0});

    for (auto _ : state)
    {
        state.PauseTiming();
        auto seed = state.iterations();
        auto v = generate_vector<long double>(SIZE, seed, 0, 1);
        state.ResumeTiming();
        quick_sort_rand(v.begin(), v.end(), state.counters);
    }
}
// Register the function as a benchmark
#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_QuickSortRandom)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_QuickSortRandom);
#endif

static void BM_MergeSort(benchmark::State &state)
{
    state.counters.insert({"comparisions", 0});
    for (auto _ : state)
    {
        state.PauseTiming();
        auto seed = state.iterations();
        auto v = generate_vector<long double>(SIZE, seed, 0, 1);
        state.ResumeTiming();
        merge_sort(v.begin(), v.end(), state.counters);
    }
}

#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_MergeSort)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_MergeSort);
#endif

static void BM_QuickSortDouble(benchmark::State &state)
{
    state.counters.insert({"comparisions", 0});

    for (auto _ : state)
    {
        state.PauseTiming();
        auto seed = state.iterations();
        auto v = generate_vector<long double>(SIZE, seed, 0, 1);
        state.ResumeTiming();
        quick_sort(v.begin(), v.end(), state.counters);
        quick_sort(v.begin(), v.end(), state.counters);
    }
}
// Register the function as a benchmark
#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_QuickSortDouble)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_QuickSortDouble);
#endif

static void BM_QuickSortRandomDouble(benchmark::State &state)
{
    state.counters.insert({"comparisions", 0});

    for (auto _ : state)
    {
        state.PauseTiming();
        auto seed = state.iterations();
        auto v = generate_vector<long double>(SIZE, seed, 0, 1);
        state.ResumeTiming();
        quick_sort_rand(v.begin(), v.end(), state.counters);
        quick_sort_rand(v.begin(), v.end(), state.counters);
    }
}
// Register the function as a benchmark
#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_QuickSortRandomDouble)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_QuickSortRandomDouble);
#endif

static void BM_MergeSortDouble(benchmark::State &state)
{
    state.counters.insert({"comparisions", 0});
    for (auto _ : state)
    {
        state.PauseTiming();
        auto seed = state.iterations();
        auto v = generate_vector<long double>(SIZE, seed, 0, 1);
        state.ResumeTiming();
        merge_sort(v.begin(), v.end(), state.counters);
        merge_sort(v.begin(), v.end(), state.counters);
    }
}

#ifdef OVERRIDE_ITERATIONS
BENCHMARK(BM_MergeSortDouble)->Iterations(ITERATIONS);
#else
BENCHMARK(BM_MergeSortDouble);
#endif

BENCHMARK_MAIN();