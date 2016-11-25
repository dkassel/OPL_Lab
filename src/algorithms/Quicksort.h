#ifndef OPL_QUICKSORT_H
#define OPL_QUICKSORT_H

#include <array>

using namespace std;


template<typename T, size_t SIZE>
void quickSortAnArray(array<T, SIZE> &a, int startIndex, int endIndex) {

    int pivotIndex = (endIndex - startIndex) / 2;
    cout << "pivotelem " << pivotIndex << endl;
    if (pivotIndex > 0) {
//        cout << "pivotelem " << a[pivotIndex] << endl;
        int j = pivotIndex + 1;
        for (int i = startIndex; i < pivotIndex; i++) {
            while (a[i] > a[pivotIndex] && j <= endIndex) {
//                cout << "i " << i << " , j " << j << endl;
                swap(a[i], a[j]);
                j++;
            }
        }
        cout << "Result: " << endl;
        for (size_t i = 0; i < 8; i++) {
            cout << "Value: " << a[i] << endl;
        }

        cout << startIndex << " " << endIndex << endl;

        quickSortAnArray(a, startIndex, pivotIndex - 1);
        quickSortAnArray(a, pivotIndex + 1, endIndex);
    }
    /*
    cout << "Pivot: " << a[pivotIndex] << endl << endl;

    for (size_t i = 0; i < SIZE; i++) {
        cout << "Value: " << a[i] << endl;
    }
     */

}

/*
template<typename T, size_t SIZE>
void quickSortAnArray(array<T, SIZE> &a) {
    quickSortAnArray(a, 0, SIZE - 1);
//    void quickSortAnArray(array<T, SIZE> &a, size_t startIndex, size_t endIndex) {


    size_t arrSize = endIndex - startIndex;
    size_t pivot1 = arrSize / 3;
    size_t pivot2 = pivot1 + 1 + (arrSize / 3);
    cout << pivot1 << " " << pivot2 << endl;


}
   */



template<typename T, size_t SIZE>
void quickSort(array<T, SIZE> &arr, int startIndex, int endIndex) {
    int i = startIndex, j = endIndex;
    int pivot = arr[(startIndex + endIndex) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };

    /* recursion */
    if (startIndex < j)
        quickSort(arr, startIndex, j);
    if (i < endIndex)
        quickSort(arr, i, endIndex);
}

#endif //OPL_QUICKSORT_H

