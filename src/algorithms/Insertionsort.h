#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H


#include <array>
#include "MinimumSearch.h"


using namespace std;


template<typename T, size_t SIZE>
void insertionSortOnArray(array<T, SIZE> &a) {
    for (size_t i = 1; i < SIZE; i++) {
        for (size_t j = i - 1; a[j] > a[j + 1]; j--) {
            swap(a[j + 1], a[j]);
        }
    }
}


template<typename T, size_t SIZE>
void insertionSortOnArrayWithPrefetch(array<T, SIZE> &a) {
    for (size_t i = 1; i < SIZE; i++) {
        __builtin_prefetch(&a[0]);
        for (size_t j = i - 1; a[j] > a[j + 1]; j--) {
            swap(a[j + 1], a[j]);
        }
    }
}

#endif //OPL_INSERTIONSORT_H
