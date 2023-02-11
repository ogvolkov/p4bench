cmake_minimum_required(VERSION 3.10)
set(BENCHMARK_DOWNLOAD_DEPENDENCIES TRUE)
add_compile_options(-O3)
project(benchp4)
add_subdirectory(benchmark)
add_executable(benchp4 main.cpp)
target_link_libraries(benchp4 benchmark::benchmark)

