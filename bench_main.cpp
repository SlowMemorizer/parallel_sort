#include "header/essential_header.h"  // if you see warning messages for this header, just ignore.
#include <algorithm>    // std::transform()
#include <vector>
#include <random>

value_t lst[LIST_SIZE];
value_t temp[LIST_SIZE];

int main(int argc, char* argv[])
{
    int read_count;
    double time;
    std::string method = argv[1];
    std::transform(method.begin(), method.end(), method.begin(), ::tolower);
    FILE* out = fopen(argv[2], "w+");   

    for(int i=0; i < LIST_SIZE; ++i) lst[i] = i + 1;
    auto rng = std::default_random_engine {};
    std::shuffle(&lst[0], &lst[LIST_SIZE], rng);

    for(int sz = 1; sz < LIST_SIZE; sz *= 4) {
        read_count = sz;
        time = run_sort(method, lst, 0, read_count-1, temp);
        fprintf(out, "%10d, %10s, %10lf\n", read_count, method.c_str(), time);
        fflush(out);
        fprintf(stdout, "%10d, %10s, %10lf\n", read_count, method.c_str(), time);
    }

    return 0;
}
