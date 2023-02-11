# Benchmarking powers of 4 check
What is the fastest way to check if a number is a power of 4?

(for purely recreational purposes)

# Build and run
Needs cmake and [benchmark](https://github.com/google/benchmark) (installed in  a subdirectory).
```
cmake ..
cmake --build .
./benchp4
```
# Results
```
Run on (32 X 2995.2 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x16)
  L1 Instruction 32 KiB (x16)
  L2 Unified 2048 KiB (x16)
  L3 Unified 36864 KiB (x1)
Load Average: 1.28, 0.57, 0.27
***WARNING*** Library was built as DEBUG. Timings may be affected.
------------------------------------------------------
Benchmark            Time             CPU   Iterations
------------------------------------------------------
BM_While    7854176261 ns   7854016900 ns            1
BM_Bit      3603603179 ns   3603604700 ns            1
BM_BitMath  3792261702 ns   3792263200 ns            1
BM_Log      1.5332e+10 ns   1.5332e+10 ns            1
BM_Switch   7758496268 ns   7758498600 ns            1
BM_Rec      7373462321 ns   7373464700 ns            1
BM_PopCount 6007790401 ns   6007792400 ns            1
```