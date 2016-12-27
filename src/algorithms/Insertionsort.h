#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H


#include <array>
#include "MinimumSearch.h"


using namespace std;


template<typename T, size_t SIZE>
void insertionSortOnArray(array<T, SIZE> &a) {
    for (size_t i = 1; i < SIZE; i++) {
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {
            swap(a[j], a[j - 1]);
        }
    }
}


template<typename T, size_t SIZE>
void insertionSortOnArrayWithPrefetch(array<T, SIZE> &a) {
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    for (size_t i = 1; i < SIZE; i++) {

        for (size_t j = i + cacheRange; j > cacheRange;) {
            j -= cacheRange;
            __builtin_prefetch(&a[j - cacheRange]);

            for (size_t k = 0; j - k >= 1 && a[j - 1 - k] > a[j - k] && k < cacheRange; k++) {
                swap(a[j - 1 - k], a[j - k]);
            }
        }
    }
}


#endif //OPL_INSERTIONSORT_H
