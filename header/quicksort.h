#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "type.h"

index_t partition(list_t lst, index_t begin, index_t end, value_t pivot)
{
    index_t i = begin, j = end;

    while(i <= j) {
        while(lst[i] < pivot) ++i;
        while(lst[j] > pivot) --j;
        if(i <= j) Swap(&lst[i++], &lst[j--]);        
    }
    return j; // |begin - - - - -j|, |j+1 - - - - - - end| 
}

void quicksort(list_t lst, index_t begin, index_t end)
{
    if(end - begin <= 1) return;
    index_t part_point = partition(lst, begin, end, lst[(begin + end)/2]);
    quicksort(lst, begin, part_point);
    quicksort(lst, part_point+1, end);
}

#endif // QUICKSORT_H_
