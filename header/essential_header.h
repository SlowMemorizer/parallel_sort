#ifndef ESSENTIAL_HEADER_H_
#define ESSENTIAL_HEADER_H_

#include "type.h"
#include "parallel_mergesort.h"
#include "parallel_quicksort.h"
#include "bubblesort.h"
#include "mergesort.h"
#include "quicksort.h"

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <string>

static const int EXIT = 0;

int read_data(FILE* in, list_t lst)
{
    int read_count = 0;
    for(int i=0; fscanf(in, "%d", &lst[i]) != EOF; ++i)
        ++read_count;
    return read_count;
}

void write_data(FILE* out, list_t lst, int read_count)
{
    for(int i=0; i < read_count;) {
        fprintf(out, "%10d ", lst[i]);
        if((++i) % 5 == 0) fprintf(out, "\n");
    }   
}

double get_time(struct timeval* start, struct timeval* end)
{
    return (double) (end->tv_sec)
          +(double) (end->tv_usec)   / 1000000.0
          -(double) (start->tv_sec)
          -(double) (start->tv_usec) / 1000000.0;
}

void print_usage(int argc)
{
    if(argc != 4) {
        printf("Usage: <exec_file> <sorting_method> <input_file> <output_file>\n\n");
        printf("    - sorting_method: bubble, merge, quick, par_merge, par_quick\n\n");
        printf("      ex) ./a.out par_quick ../data30 out\n");
        exit(1);
    }

}
double run_sort(std::string method, list_t lst, index_t begin, index_t end, list_t temp)
{
    struct timeval start_p, end_p;

    gettimeofday(&start_p, NULL);

    if(method == "bubble")         bubblesort(lst, begin, end); 
    else if(method == "merge")     mergesort(lst, begin, end, temp);
    else if(method == "quick")     quicksort(lst, begin, end);
    else if(method == "par_merge") parallel_mergesort(lst, begin, end, temp);
    else if(method == "par_quick") parallel_quicksort(lst, begin, end);
    else print_usage(EXIT); 

    gettimeofday(&end_p, NULL); 

    return get_time(&start_p, &end_p);
}

#endif 
