#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "type.h"
#include "insertion_sort.h"

void merge(list_t lst, index_t begin, index_t mid, index_t end, list_t temp)
{
    index_t pleft = begin;   
    index_t pright = mid + 1;   
    index_t ptmp = begin;

    while(pleft <= mid && pright <= end)
    {
        if(lst[pleft] <= lst[pright])
            temp[ptmp++] = lst[pleft++];
        else
            temp[ptmp++] = lst[pright++];
    }

    while(ptmp <= end)
    {
        if(pleft > mid) 
            temp[ptmp++] = lst[pright++];
        else            
            temp[ptmp++] = lst[pleft++];
    }

    for(ptmp = begin; ptmp <= end; ++ptmp)
        lst[ptmp] = temp[ptmp];            
}

void mergesort(list_t lst, index_t begin, index_t end, list_t temp)
{
    if(end - begin < ISORT_MAX) 
        insertion_sort(lst, begin, end);
    else {
        index_t mid = (begin + end) / 2;
    
        mergesort(lst, begin, mid, temp);
        mergesort(lst, mid+1, end, temp);
        merge(lst, begin, mid, end, temp);     
    }
}

#endif // MERGESORT_H_
