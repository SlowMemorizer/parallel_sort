#!/bin/bash
mkdir build

g++ -Ofast -fopenmp -pthread -std=c++11 main.cpp -o build/main
g++ -O3 -std=c++11 is_sorted.cpp -o build/is_sorted
