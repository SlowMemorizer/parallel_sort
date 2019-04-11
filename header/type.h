#ifndef TYPE_H_
#define TYPE_H_

#include <stdint.h>
#define LIST_SIZE 80000000     // 80M
#define ISORT_MAX 32

typedef int32_t* list_t;
typedef int32_t  index_t;
typedef int32_t  value_t;

inline void Swap(value_t* a, value_t* b)
{
    value_t temp = *a;
    *a = *b;
    *b = temp;
}

#endif //TYPE_H_
