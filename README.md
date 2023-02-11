# Benchmarking powers of 4 check
What is the fastest way to check if a number is a power of 4?

(for purely recreational purposes because https://leetcode.com/problems/power-of-four/)

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
Load Average: 0.68, 0.25, 0.09
***WARNING*** Library was built as DEBUG. Timings may be affected.
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_While      6781486783 ns   6781456100 ns            1
BM_Bit        3605547419 ns   3605546200 ns            1
BM_BitNegMask 3608959881 ns   3608961300 ns            1
BM_BitMath    3825331908 ns   3825332100 ns            1
BM_Log        1.5407e+10 ns   1.5407e+10 ns            1
BM_Switch     7766807456 ns   7766805600 ns            1
BM_Rec        7493509379 ns   7493511600 ns            1
BM_PopCount   5775810452 ns   5775812500 ns            1
```