#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H


#include <array>
#include "MinimumSearch.h"


using namespace std;

class InsertionSort {
public:
    template<typename T, size_t SIZE>
    void insertionSortOnArray(array<T, SIZE> &a);
};

template<typename T, size_t SIZE>
void InsertionSort::insertionSortOnArray(array<T, SIZE> &a) {
    T temp;
    for (size_t i = 1; i < SIZE; i++) {
        temp = a[i];
        T j = i;
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}


#endif //OPL_INSERTIONSORT_H
