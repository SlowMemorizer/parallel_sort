#ifndef PARALLEL_QUICKSORT_H_
#define PARALLEL_QUICKSORT_H_

#include "omp.h"
#include "insertion_sort.h"
#include "quicksort.h"    // partition()
#include "type.h"

#define LEN_LIMIT 1024
#define NUM_THREADS 16

void run_quicksort(list_t lst, index_t begin, index_t end)
{
    if(end - begin < ISORT_MAX) {
        insertion_sort(lst, begin, end);
        return;
    }
    
    index_t part_point = partition(lst, begin, end, lst[(begin + end)/2]);
  
    if(end - begin < LEN_LIMIT) {
    	run_quicksort(lst, begin, part_point);
        run_quicksort(lst, part_point+1, end);
    } else {
        #pragma omp task
        run_quicksort(lst, begin, part_point);
        #pragma omp task 
        run_quicksort(lst, part_point+1, end);
    }
}

void parallel_quicksort(list_t lst, index_t begin, index_t end)
{
    #pragma omp parallel num_threads(NUM_THREADS) 
    {
        #pragma omp master
        run_quicksort(lst, begin, end);
	// implicit barrier(wait until all tasks(sorting) are finished.)
    } 
}

#endif // MULTI_QUICKSORT_H_
