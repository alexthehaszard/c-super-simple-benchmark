#include "benchmark.hpp"

#include <ranges>
#include <iostream>

int main()
{
    // gather up what we will be benchmarking
    auto const ints = {0, 1, 2, 3, 4, 5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    int result = 0;
    auto ranges_func = [&]() {
        for (int i : ints | std::views::filter(even) | std::views::transform(square))
            result += i;
    };

    // do the benchmarking
    Benchmarker ranges_bench;
    for (size_t i{0}; i < 100; ++i)
    {
        ranges_bench.benchmark(ranges_func);
    }
    // print the results to cout
    std::cout << ranges_bench.benchmark_stats() << std::endl;

    return 0;
}