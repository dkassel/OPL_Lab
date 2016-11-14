#ifndef OPL_SELECTIONSORT_H
#define OPL_SELECTIONSORT_H


#include <array>
#include "MinimumSearch.h"

using namespace std;


template<typename T, size_t SIZE>
void selectionSortAnArray(array<T, SIZE> &a) {
    for (size_t i = 0; i < SIZE; i++) {
        swap(a[i], *findMinimumInRange(a, i, SIZE - 1));
    }
}


template<typename T, size_t SIZE>
void selectionSortAnArrayWithJumpCacheline(array<T, SIZE> &a) {
    for (size_t i = 0; i < SIZE; i++) {
        swap(a[i], *findMinimumWithJumpCachelineInRange(a, i, SIZE - 1));
    }
}


template<typename T, size_t SIZE>
void selectionSortAnArrayWithPrefetch(array<T, SIZE> &a) {
    for (size_t i = 0; i < SIZE; i++) {
        swap(a[i], *findMinimumWithPrefetchInRange(a, i, SIZE - 1));
    }
}


#endif //OPL_SELECTIONSORT_H