#ifndef OPL_MERGESORT_H
#define OPL_MERGESORT_H

#include <array>

using namespace std;

class MergeSort {
public:
    template<typename T, size_t SIZE>
    void mergeSortOnArray(array<T, SIZE> &a);
};

#endif //OPL_MERGESORT_H
