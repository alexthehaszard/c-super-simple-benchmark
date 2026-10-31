#include <functional>
#include <chrono>
#include <string>
#include <format>

using namespace std::chrono_literals;

class Benchmarker
{
public:
    void benchmark(const std::function<void()>& func_to_benchmark)
    {
        // benchmark function
        auto start = std::chrono::high_resolution_clock::now();
        func_to_benchmark();
        auto end = std::chrono::high_resolution_clock::now();

        // add stats
        std::chrono::nanoseconds time_taken = end - start;
        data_points++;
        if (time_taken < minimum_runtime) minimum_runtime = time_taken;
        if (time_taken > maximum_runtime) maximum_runtime = time_taken;

        double ratio = 1.0 / data_points;
        average_runtime *= 1 - ratio;
        average_runtime += time_taken * ratio;
    }

    std::string benchmark_stats()
    {
        return std::format(
            "Average runtime: {}\nMinimum runtime: {}\nMaximum runtime: {}\nData points: {}",
            average_runtime,
            minimum_runtime,
            maximum_runtime,
            data_points
        );
    }
private:
    std::chrono::duration<double, std::nano> average_runtime{0ns};
    std::chrono::nanoseconds minimum_runtime{std::chrono::nanoseconds::max()};
    std::chrono::nanoseconds maximum_runtime{0ns};
    size_t data_points{0};
};

