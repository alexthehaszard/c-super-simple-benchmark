# c++ super simple benchmark

Just a super simple class that can be used to benchmark a function.

There is an example usage in `main.cpp`, and the benchmarking class is in `benchmark.hpp`.
It is so small, I didn't even include any documentation for the class. You can just read what it does if you are interested.

## building & running

The benchmark file is header-only, so you can just copy it into your project and include it directly. It depends on a few part of the standard library (functional, chrono, string, format).

To run the test app, you can run

```sh
make run
```

It uses clang with standard version c++23.
