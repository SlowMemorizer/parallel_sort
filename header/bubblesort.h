#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "type.h"
#include <stdbool.h>

void bubblesort(list_t lst, index_t begin, index_t end)
{
    int size = end - begin + 1;
    index_t i, j;
    bool swapped = false;

    for(i = 0; i < size-1; ++i) 
    {
        for(j = 0; j < size-i-1; ++j) 
        {
            if(lst[j] > lst[j+1]) 
            {
                Swap(&lst[j], &lst[i]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }       
}

#endif // BUBBLE_SORT_H
