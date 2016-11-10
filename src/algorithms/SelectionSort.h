#ifndef OPL_SELECTIONSORT_H
#define OPL_SELECTIONSORT_H


#include <array>
#include "MinimumSearch.h"

using namespace std;

class SelectionSort {
public:
    enum searchtype { normal, cachelinejump, prefetch };

    template<typename T, size_t SIZE>
    void selectionSortAnArray(array<T, SIZE> &a, searchtype stype);
};

template<typename T, size_t SIZE>
void SelectionSort::selectionSortAnArray(array<T, SIZE> &a, searchtype stype) {
    MinimumSearch minimumSearch;

    for (size_t i = 0; i < SIZE; i++) {
        T *j;
        switch(stype)
        {
            case normal:
                j = minimumSearch.findMinimumInRange(a, i, SIZE - 1);
                break;
            case cachelinejump:
                j = minimumSearch.findMinimumWithJumpCachelineInRange(a, i, SIZE - 1);
                break;
            case prefetch:
                j = minimumSearch.findMinimumWithPrefetchInRange(a, i, SIZE - 1);
                break;
        }
        swap(a[i], *j);
    }
    //for (size_t i = 0; i < SIZE; i++) { cout << a[i] << endl; }

}


#endif //OPL_SELECTIONSORT_H