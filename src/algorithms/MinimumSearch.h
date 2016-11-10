#ifndef OPL_MINIMUMSEARCH_H
#define OPL_MINIMUMSEARCH_H

#include <array>

using namespace std;

const size_t CACHE_LINE_SIZE = 64;

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
};


template<typename T, size_t SIZE>
T *MinimumSearch::findMinimum(array<T, SIZE> &a) {
    return findMinimumInRange(a, 0, SIZE - 1);
}


template<typename T, size_t SIZE>
T *MinimumSearch::findMinimumInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    size_t arraySize = a.size();

    if (endIndex > arraySize - 1)
        throw out_of_range("endIndex out of range");
    if (startIndex < 0 || startIndex > arraySize - 1)
        throw out_of_range("startIndex out of range");

    T *minValue = &a[startIndex];

    for (size_t i = startIndex + 1; i <= endIndex; i++) {
        if (*minValue > a[i])
            minValue = &a[i];
    }
    return minValue;
}


template<typename T, size_t SIZE>
T *MinimumSearch::findMinimumWithJumpCacheline(array<T, SIZE> &a) {
    return findMinimumWithJumpCachelineInRange(a, 0, SIZE - 1);
}


template<typename T, size_t SIZE>
T *MinimumSearch::findMinimumWithJumpCachelineInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    size_t arraySize = SIZE;

    if (endIndex > arraySize - 1)
        throw out_of_range("endIndex out of range");
    if (startIndex < 0 || startIndex > arraySize - 1)
        throw out_of_range("startIndex out of range");

    T *minValue = &a[startIndex];
    //T *tempValue = &a[startIndex];

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        // Load into cache
        if (i + cacheRange <= endIndex) {
            a[i + cacheRange];
        }

        // Search for value in cacherange.
        size_t rangeIndex = i + cacheRange;
        for (size_t j = i; j < rangeIndex && j <= endIndex; j++) {
            if (a[j] < *minValue)
                minValue = &a[j];
        }
    }
    //cout << *tempValue << endl;
    return minValue;
}

template<typename T, size_t SIZE>
T *MinimumSearch::findMinimumWithPrefetch(array<T, SIZE> &a) {
    return findMinimumWithPrefetchInRange(a, 0, SIZE - 1);
}

template<typename T, size_t SIZE>
T *MinimumSearch::findMinimumWithPrefetchInRange(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {
    size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    size_t arraySize = SIZE;

    if (endIndex > arraySize - 1)
        throw out_of_range("endIndex out of range");
    if (startIndex < 0 || startIndex > arraySize - 1)
        throw out_of_range("startIndex out of range");

    T *minValue = &a[startIndex];
    //T *tempValue = &a[startIndex];

    // Cacheline loop
    for (size_t i = startIndex; i <= endIndex; i += cacheRange) {
        __builtin_prefetch(&a[i + cacheRange], 0, 3);

        // Search for value in cacherange.
        size_t rangeIndex = i + cacheRange;
        for (size_t j = i; j < rangeIndex && j <= endIndex; j++) {
            if (a[j] < *minValue)
                minValue = &a[j];
        }
    }
    //   cout << *tempValue << endl;
    return minValue;
}

#endif //OPL_MINIMUMSEARCH_H