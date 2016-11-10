#ifndef OPL_QUICKSORT_H
#define OPL_QUICKSORT_H

#include <array>

using namespace std;

class QuickSort {
public:
    template<typename T, size_t SIZE>
    void quickSortOnArray(array<T, SIZE> &a);
};

#endif //OPL_QUICKSORT_H
