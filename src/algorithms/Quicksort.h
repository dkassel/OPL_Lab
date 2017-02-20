#ifndef OPL_QUICKSORT_H
#define OPL_QUICKSORT_H

#include <array>
#include "Insertionsort.h"
#include "Mergesort.h"
#include <iostream>

using namespace std;


/*
 * Quicksort mit three-way-partitioning (Wichtig: a[r] mit a[ (l + r) / 2] vertauschen) in zwei Varianten:
 * - Normale,
 * - Eine Hybride Variante, bei der die Rekursion früher abgebrochen wird und der Rest mit Sortieren durch
 * Direktem Einfügen sortiert wird sowie der schlimmste Fall von Quicksort erkannte wird und in diesem Fall in der Mitte
 * geteilt, rekursiv sortiert und dann genau ein merge-Schritt danach durchgeführt wird.
 */


template<typename T, size_t SIZE>
void quickSort(array<T, SIZE> &a, size_t lo, size_t hi) {
    size_t i = lo - 1;
    size_t j = hi;
    // Overflow mit unsigned integer verhindern.
    size_t p = lo;
    size_t q = hi;
    swap(a[(lo + hi) / 2], a[hi]);  // Pivot Elem wählen.

    T v = a[hi];

    if (hi <= lo) return;

    for (;;) {
        while (a[++i] < v);

        while (v < a[--j])
            if (j == lo) break;

        if (i >= j)
            break;

        swap(a[i], a[j]);

        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }
        if (v == a[j]) {
            q--;
            swap(a[j], a[q]);
        }
    }
    swap(a[i], a[hi]);

    // Overflow mit unsigned integer verhindern.
    i == 0 ? j = 0 : j = i - 1;
    i = i + 1;


    size_t k = lo;

    while (k < p) {
        swap(a[k], a[j]);
        k++;

        if (j > 0)
            j--;
    }
    k = hi - 1;
    while (k > q) {
        swap(a[i], a[k]);
        i++;
        if (k > 0)
            k--;
    }

    quickSort(a, lo, j);
    quickSort(a, i, hi);
}

template<typename T, size_t SIZE>
void quickSort(array<T, SIZE> &a) {
    quickSort(a, 0, SIZE - 1);
}


const int CUT_OFF = 10;  // Wert, ab dem Quicksort ineffizient ist und stattdessen insertionsort benutzt werden soll.

template<typename T, size_t SIZE>
void quicksortHybrid(array<T, SIZE> &a, array<T, SIZE> &aux, size_t lo, size_t hi) {

    if (hi - lo < CUT_OFF) {
        insertionSortOnArray(a, lo, hi + 1);
    } else {

        size_t i = lo - 1;
        size_t j = hi;
        // prevent overflow with unsigned integer.
        size_t p = lo;
        size_t q = hi;

        // Verwende mittleres Element als Pivot-Element.
        swap(a[(lo + hi) / 2], a[hi]);

        T v = a[hi];
        if (hi <= lo) return;

        for (;;) {
            while (a[++i] < v);

            while (v < a[--j])
                if (j == lo) break;

            if (i >= j)
                break;

            swap(a[i], a[j]);

            if (a[i] == v) {
                p++;
                swap(a[p], a[i]);
            }
            if (v == a[j]) {
                q--;
                swap(a[j], a[q]);
            }
        }
        swap(a[i], a[hi]);
        // prevent overflow with unsigned integer.
        i == 0 ? j = 0 : j = i - 1;
        i = i + 1;

        size_t k = lo;
        while (k < p) {
            swap(a[k], a[j]);
            k++;
            // prevent overflow with unsigned integer.
            if (j > 0)
                j--;
        }

        k = hi - 1;
        while (k > q) {
            swap(a[i], a[k]);
            i++;
            // prevent overflow with unsigned integer.
            if (k > 0)
                k--;
        }

        if ((j - lo) > (CUT_OFF * (hi - i)) || (hi - i) > ((j - lo) * CUT_OFF)) {
            int mid = (lo + hi) / 2;
            quicksortHybrid(a, aux, lo, mid);
            quicksortHybrid(a, aux, mid + 1, hi);
            merge(a, aux, lo, mid, hi);
        } else {
            quicksortHybrid(a, aux, lo, j);
            quicksortHybrid(a, aux, i, hi);
        }
    }
}


template<typename T, size_t SIZE>
void quicksortHybrid(array<T, SIZE> &a) {
    array<T, SIZE> *aux = new array<T, SIZE>();
    quicksortHybrid(a, *aux, 0, SIZE - 1);
    delete aux;
}


#endif //OPL_QUICKSORT_H

