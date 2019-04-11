#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include "type.h"

void insertion_sort(list_t lst, index_t begin, index_t end) {
    index_t i, j;
    value_t save;
    for(i = begin+1; i <= end; ++i) {
        j = i;
        save = lst[j];
        while(--j >= begin && save < lst[j]) {
            lst[j+1] = lst[j];
            lst[j] = save;
        }
    }
}

#endif // INSERTION_SORT_H_
 
