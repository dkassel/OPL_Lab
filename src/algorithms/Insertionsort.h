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
    size_t cacheCnt;

    for (size_t i = 1; i < SIZE; i++) {
        cacheCnt = 0;
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {
            if (cacheCnt <= 0) {
                __builtin_prefetch(&a[j - cacheRange]);
                cacheCnt = cacheRange;
            }
            cacheCnt--;
            swap(a[j], a[j - 1]);
        }
    }
}

/*
template<typename T, size_t SIZE>
void insertionSortOnArrayWithPrefetchOld(array<T, SIZE> &a) {
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    for (size_t i = 1; i < SIZE; i += cacheRange) {   // Iteriere über array in cache schritten bis zum ende.

        __builtin_prefetch(&a[i]);  // Prefetch an aktueller stelle

        for (size_t j = i - 1; j < i + cacheRange && j < SIZE; j++) {
            if (j + 1 < SIZE && a[j] > a[j + 1])
                swap(a[j + 1], a[j]);
            else break;
        }


        for (size_t k = i; k < i + cacheRange && k < SIZE; k++) {


            for (size_t j = i - 1; a[j] > a[j + 1]; j--) {
                swap(a[j + 1], a[j]);
            }
            cacheCounter++;
        }

    }
}
*/

#endif //OPL_INSERTIONSORT_H
