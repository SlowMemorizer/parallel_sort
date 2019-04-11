#include "header/essential_header.h"  // if you see warning messages for this header, just ignore.
#include <algorithm>    // std::transform()

value_t lst[LIST_SIZE];
value_t temp[LIST_SIZE];

int main(int argc, char* argv[])
{
    print_usage(argc);

    int read_count;
    double time;
    std::string method = argv[1];
    std::transform(method.begin(), method.end(), method.begin(), ::tolower);
    FILE* in  = fopen(argv[2], "r");    // for faster reading than std::fstream;
    FILE* out = fopen(argv[3], "w+");

    read_count = read_data(in, lst);
    time = run_sort(method, lst, 0, read_count-1, temp);
    write_data(out, lst, read_count);  

    printf("%10d, %10s, %10lfs\n", read_count, method.c_str(), time);

    fclose(in), fclose(out);
    return 0;
}
