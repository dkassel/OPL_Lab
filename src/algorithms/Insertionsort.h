#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H


#include <array>
#include "MinimumSearch.h"


using namespace std;

/* ----- AUFGABE C -----
 * Direktes Einfügen. Der in den linken Bereich einzufügende Wert soll ähnlich wie bei Bubblesort von rechts nach links
 * an die richtige Stelle wandern. Zwei Varianten: Normal, Mit prefetch für die inneren Schleife
  */



// ----- Variante 1: Normal -----
template<typename T, size_t SIZE>
void insertionSortOnArray(array<T, SIZE> &a, size_t l, size_t r) {
    for (size_t i = l + 1; i < r; i++) {
        for (size_t j = i; j > l && a[j - 1] > a[j]; j--) {
            swap(a[j], a[j - 1]);
        }
    }
}

template<typename T, size_t SIZE>
void insertionSortOnArray(array<T, SIZE> &a) {
    insertionSortOnArray(a, 0, SIZE);
}

template<typename T, size_t SIZE>
void insertionSortWithPrefetch(array<T, SIZE> &a) {
    const size_t cacheRange = CACHE_LINE_SIZE / sizeof(T);
    for (size_t i = 1; i < SIZE; i++)
        for (size_t j = i + cacheRange; j > cacheRange;) {
            j -= cacheRange;
            __builtin_prefetch(&a[j - cacheRange]);
            for(size_t k = j; k > 0  && a[k - 1] > a[k]; k--)
                swap(a[k], a[k-1]);
        }
}





#endif //OPL_INSERTIONSORT_H
