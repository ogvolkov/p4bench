#include <benchmark/benchmark.h>
#include <cmath>
#include <limits>

bool p4While(int n) {
  if (n <= 0) return false;
  while (n > 1) {
      if (n % 4 != 0) return false;
      n /= 4;
  }
  return true;
}

const int POWERS_4_MASK = 0b1010101010101010101010101010101;
bool p4Bit(int n) {
  return n > 0 && ((n | POWERS_4_MASK) == POWERS_4_MASK) && ((n & (n-1)) == 0);
}

const int POWERS_4_NEG_MASK = 0b101010101010101010101010101010;
bool p4BitNegMask(int n) {
  return n > 0 && ((n & POWERS_4_NEG_MASK) == 0) && ((n & (n-1)) == 0);
}

bool p4BitMath(int n) {
  return n > 0 && ((n & (n-1)) == 0) && (n % 3 == 1);
}

bool p4Log(int n) {
    if (n <= 0) return false;
    auto l = log2(n) / 2;
    return l - (int)l == 0;
}

bool p4Switch(int n) {
  switch (n) {
      case 1:
      case 4:
      case 16:
      case 64:
      case 256:
      case 1024:
      case 4096:
      case 16384:
      case 65536:
      case 262144:
      case 1048576:
      case 4194304:
      case 16777216:
      case 67108864:
      case 268435456:
      case 1073741824:
          return true;
      default:
          return false;
  }
}

bool p4Rec(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    return n % 4 == 0 && p4Rec(n/4);
}

bool p4PopCount(int n) {
  return n > 0 && __builtin_popcount(n) == 1 && (__builtin_popcount(n-1) & 1) == 0;
}

static void BM_While(benchmark::State& state) {
  for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4While(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_While);

static void BM_Bit(benchmark::State& state) {
  for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4Bit(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_Bit);

static void BM_BitNegMask(benchmark::State& state) {
  for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4BitNegMask(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_BitNegMask);

static void BM_BitMath(benchmark::State& state) {
  for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4BitMath(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_BitMath);

static void BM_Log(benchmark::State& state) {
  for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4Log(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_Log);

static void BM_Switch(benchmark::State& state) {
 for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4Switch(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_Switch);

static void BM_Rec(benchmark::State& state) {
  for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4Rec(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_Rec);

static void BM_PopCount(benchmark::State& state) {
 for (auto _ : state) {
    for (auto n = std::numeric_limits<int>::min();;n++) {
      benchmark::DoNotOptimize(p4PopCount(n));
      if (n == std::numeric_limits<int>::max()) break;
    }
  }
}
BENCHMARK(BM_PopCount);

BENCHMARK_MAIN();