cmake_minimum_required(VERSION 3.28)
project(A1)

set(CMAKE_CXX_STANDARD 20)

add_executable(A1 main.cpp
        StringGenerator.cpp
        Sorter.cpp
        Sorter.h
        q_sort.cpp
        sort.h
        merge_sort.cpp
        sort.cpp
        q_sort_string.cpp
        merge_sort_string.cpp
        radix_sort_string.cpp
)
