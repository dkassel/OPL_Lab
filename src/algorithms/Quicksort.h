#ifndef OPL_QUICKSORT_H
#define OPL_QUICKSORT_H

#include <array>

using namespace std;


template<typename T, size_t SIZE>
void quickSort(array<T, SIZE> &a, int l, int r) {
    int i = l - 1;
    int j = r;
    int p = l - 1;
    int q = r;

    // Verwende mittleres Element als Pivot-Element.
    swap(a[(l + r) / 2], a[r]);

    T v = a[r];
    if (r <= l) return;

    for (;;) {
        while (a[++i] < v);

        while (v < a[--j])
            if (j == l) break;

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
    swap(a[i], a[r]);
    j = i - 1;
    i = i + 1;

    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);

    quickSort(a, l, j);
    quickSort(a, i, r);
}

template<typename T, size_t SIZE>
void quickSort(array<T, SIZE> &arr) {
    quickSort(arr, 0, (int) SIZE - 1);
}


#endif //OPL_QUICKSORT_H

