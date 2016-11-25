#ifndef OPL_MINIMUMSEARCH_H
#define OPL_MINIMUMSEARCH_H

#include <array>

using namespace std;

const size_t CACHE_LINE_SIZE = 64;


template<typename T, size_t SIZE>
T *findMinimumInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    /*
    T *minValue = &a[startIndex];

    for (size_t i = startIndex + 1; i <= endIndex; i++) {
        if (*minValue > a[i]) {
            minValue = &a[i];
        }
    }
    return minValue;
     */

    size_t minValueIndex = startIndex;
    for (size_t i = startIndex + 1; i <= endIndex; i++) {
        if (a[minValueIndex] > a[i]) {
            minValueIndex = i;
        }
    }
    return &a[minValueIndex];
}


template<typename T, size_t SIZE>
T *findMinimum(array<T, SIZE> &a) {
    return findMinimumInRange(a, 0, SIZE - 1);
}


template<typename T, size_t SIZE>
T *findMinimumWithJumpCachelineInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    /*
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    T *minValue = &a[startIndex];

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {

        // Search for value in cacherange.
        for (size_t j = i; j < i + cacheRange && j <= endIndex; j++) {
            if (a[j] < *minValue) {
                minValue = &a[j];
            }
        }
    }
    return minValue;
*/

    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    size_t minValueIndex = startIndex;

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        // Search for value in cacherange.
        for (size_t j = i; j < i + cacheRange && j <= endIndex; j++) {
            if (a[minValueIndex] > a[j]) {
                minValueIndex = j;
            }
        }
    }
    return &a[minValueIndex];
}

template<typename T, size_t SIZE>
T *findMinimumWithJumpCacheline(array<T, SIZE> &a) {
    return findMinimumWithJumpCachelineInRange(a, 0, SIZE - 1);
}


template<typename T, size_t SIZE>
T *findMinimumWithPrefetchInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    /*
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);

    T *minValue = &a[startIndex];

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        __builtin_prefetch(&a[i + cacheRange]);

        // Search for value in cacherange.
        for (size_t j = i; j < i + cacheRange && j <= endIndex; j++) {
            if (a[j] < *minValue) {
                minValue = &a[j];
            }
        }
    }
    return minValue;
*/

    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    size_t minValueIndex = startIndex;

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        __builtin_prefetch(&a[i + cacheRange]);
        // Search for value in cacherange.
        for (size_t j = i; j < i + cacheRange && j <= endIndex; j++) {
            if (a[minValueIndex] > a[j]) {
                minValueIndex = j;
            }
        }
    }
    return &a[minValueIndex];
}

template<typename T, size_t SIZE>
T *findMinimumWithPrefetch(array<T, SIZE> &a) {
    return findMinimumWithPrefetchInRange(a, 0, SIZE - 1);
}

#endif //OPL_MINIMUMSEARCH_H