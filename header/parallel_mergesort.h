#ifndef PARALLEL_MERGESORT_H_
#define PARALLEL_MERGESORT_H_

#include "type.h"
#include "mergesort.h"
#include <thread>

using std::thread;

void parallel_mergesort(list_t lst, index_t begin, index_t end, list_t temp)
{
    static const int THREAD_MAX = 16;
    std::thread thrs[THREAD_MAX];
    const int size = end - begin + 1;
    const int div_num = size / THREAD_MAX;
    int b = 0, m = 0, e = 0, i, j, unit;

    //Phase #1: Merge Sort 
    for(i=0; i < THREAD_MAX; ++i) {
        e = b + div_num - 1;
        if(i == THREAD_MAX-1) e = end;   
        thrs[i] = thread(mergesort, lst, b, e, temp);
        b = e + 1;
    }
    for(i=0; i < THREAD_MAX; ++i) thrs[i].join();

    // Phase #2: Merge
    for(i=THREAD_MAX/2, b=0, e=0, unit=1; i >= 1; i /= 2, unit *= 2) { 
        for(j=0, b=0, e=0, m=0; j < i; ++j) {
           m = b + (unit * div_num) - 1;
           e = m + (unit * div_num);
           if(i == 1) e = end;  
           thrs[j] = thread(merge, lst, b, m, e, temp);
           b = e + 1;
        }
        for(j=0; j < i; ++j) thrs[j].join();
    }
}

#endif // PARALLEL_MERGESORT_H_
