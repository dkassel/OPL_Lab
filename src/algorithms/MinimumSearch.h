#ifndef OPL_MINIMUMSEARCH_H
#define OPL_MINIMUMSEARCH_H

#include <array>

using namespace std;

const size_t CACHE_LINE_SIZE = 64;

/*
class MinimumSearch {
public:
    template<typename T, size_t SIZE>
    T *findMinimum(array<T, SIZE> &a);

    template<typename T, size_t SIZE>
    T *findMinimumInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex);

    template<typename T, size_t SIZE>
    T *findMinimumWithJumpCacheline(array<T, SIZE> &a);

    template<typename T, size_t SIZE>
    T *findMinimumWithJumpCachelineInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex);

    template<typename T, size_t SIZE>
    T *findMinimumWithPrefetch(array<T, SIZE> &a);

    template<typename T, size_t SIZE>
    T *findMinimumWithPrefetchInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex);

    template<typename T, size_t SIZE>
    void measureMinimumSearch(array<T, SIZE> &a, T* (*func)(array<T, SIZE> &a));
};
*/





template<typename T, size_t SIZE>
T *findMinimumInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    //printf("In find minimum\n");
    T *minValue = &a[startIndex];

    for (size_t i = startIndex + 1; i <= endIndex; i++) {
        if (*minValue > a[i])
            minValue = &a[i];
    }
    return minValue;
}

template<typename T, size_t SIZE>
T *findMinimum(array<T, SIZE> &a) {
    return findMinimumInRange(a, 0, SIZE - 1);
}


template<typename T, size_t SIZE>
T *findMinimumWithJumpCachelineInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    //printf("In jump cacheline\n");
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    T *minValue = &a[startIndex];

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        // Search for value in cacherange.
        size_t rangeIndex = i + cacheRange;
        for (size_t j = i; ((j < rangeIndex) & (j <= endIndex)); j++) {
            if (a[j] < *minValue) {
                minValue = &a[j];
            }
        }
    }
    return minValue;
}

template<typename T, size_t SIZE>
T *findMinimumWithJumpCacheline(array<T, SIZE> &a) {
    return findMinimumWithJumpCachelineInRange(a, 0, SIZE - 1);
}


template<typename T, size_t SIZE>
T *findMinimumWithPrefetchInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    //printf("In prefetch\n");
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);

    T *minValue = &a[startIndex];

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        __builtin_prefetch(&a[i + cacheRange]);

        // Search for value in cacherange.
        size_t rangeIndex = i + cacheRange;
        for (size_t j = i; ((j < rangeIndex) & (j <= endIndex)); j++) {
            if (a[j] < *minValue) {
                minValue = &a[j];
            }
        }
    }
    return minValue;
}

template<typename T, size_t SIZE>
T *findMinimumWithPrefetch(array<T, SIZE> &a) {
    return findMinimumWithPrefetchInRange(a, 0, SIZE - 1);
}

#endif //OPL_MINIMUMSEARCH_H