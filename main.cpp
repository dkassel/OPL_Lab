

#include <iostream>
#include "src/utils/ArrayFiller.h"
#include "src/algorithms/MinimumSearch.h"
#include "src/algorithms/SelectionSort.h"
#include <chrono>
#include "src/Measurement.h"


const size_t SIZE = 65536;
//const size_t SIZE = 65325000;

using namespace std;
using namespace chrono;


template<typename T, size_t ARRAYSIZE>
void minimumSearch() {
    cout << " Measure Minimum Search Algorithms, Size " << ARRAYSIZE << endl;
    array<T, ARRAYSIZE> *arr = new array<T, ARRAYSIZE>();
    stringstream outputstream;

    outputstream << "\n-- Type: Normal --\n";
    measureMinimumSearch(*arr, findMinimum, outputstream);

    outputstream << "\n-- Type: Jump Cacheline --\n";
    measureMinimumSearch(*arr, findMinimumWithJumpCacheline, outputstream);

    outputstream << "\n-- Type: Prefetch --\n";
    measureMinimumSearch(*arr, findMinimumWithPrefetch, outputstream);

    cout << outputstream.str() << endl;
    delete arr;
}

template<typename T, size_t ARRAYSIZE>
void selectionSort() {
    cout << " Measure Selection Sort Algorithms, Size " << ARRAYSIZE << endl;
    array<T, ARRAYSIZE> *arr = new array<T, ARRAYSIZE>();
    stringstream outputstream;

    outputstream << "\n-- Type: Normal --\n";
    measureSelectionSort(*arr, selectionSortAnArray, outputstream);

    outputstream << "\n-- Type: Jump Cacheline --\n";
    measureSelectionSort(*arr, selectionSortAnArrayWithJumpCacheline, outputstream);

    outputstream << "\n-- Type: Prefetch --\n";
    measureSelectionSort(*arr, selectionSortAnArrayWithPrefetch, outputstream);

    cout << outputstream.str() << endl;
    delete arr;
}


int main() {
    //minimumSearch<double, 65536>();
    //minimumSearch<double, 131072>();
    //minimumSearch<double, 262144>();
    //minimumSearch<double, 1048576>();
    //minimumSearch<double, 33554432>();
//    minimumSearch<double, 67108864>();
  //  minimumSearch<double, 134217728>();
    minimumSearch<double, 268435456>();
    //minimumSearch<double, 536870912>();
    //minimumSearch<double, 1073741824>();
    //minimumSearch<double, 2147483648>();

    selectionSort<double, 32768>();
    //selectionSort<double, 65536>();



    return 0;



}





