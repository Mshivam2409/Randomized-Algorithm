#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
// Declare a class template
template <bool is_integral, typename T>
struct uniform_distribution_selector;

// Specialize for true
template <typename T>
struct uniform_distribution_selector<true, T>
{
    using type = typename std::uniform_int_distribution<T>;
};

// Specialize for false
template <typename T>
struct uniform_distribution_selector<false, T>
{
    using type = typename std::uniform_real_distribution<T>;
};

template <typename T>
std::vector<T> generate_vector(size_t N, T lower = T(0), T higher = T(99))
{
    // Select the appropriate distribution type.
    using uniform_distribution_type = typename uniform_distribution_selector<std::is_integral<T>::value, T>::type;

    uniform_distribution_type distribution(lower, higher);
    std::mt19937 engine;
    auto generator = std::bind(distribution, engine);
    std::vector<T> vec(N);
    std::generate(vec.begin(), vec.end(), generator);
    return vec;
}