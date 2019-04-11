#!/bin/bash
mkdir build

clang++ -Ofast -fopenmp -pthread -std=c++11 main.cpp -o build/main
clang++ -O3 -std=c++11 is_sorted.cpp -o build/is_sorted
