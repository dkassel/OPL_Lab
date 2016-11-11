#ifndef OPL_MEASUREMENT_H
#define OPL_MEASUREMENT_H

#include "algorithms/MinimumSearch.h"
#include <sstream>
#include <chrono>
#include <iostream>
#include "utils/ArrayFiller.h"

using namespace std;
using namespace chrono;


template<typename T, size_t SIZE>
void measureMinimumSearch(array<T, SIZE> &a, T *(*func)(array<T, SIZE> &a), stringstream &iostream) {
    T minimum;
    for (size_t i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
                fillArrayAsc(a);
                iostream << "Result ASC : ";
                break;
            case 2:
                fillArrayDesc(a);
                iostream << "Result DESC: ";
                break;
            case 3:
                fillArrayRandom(a);
                iostream << "Result RAND: ";
                break;
        }
        clearCache();

        high_resolution_clock::time_point start = high_resolution_clock::now();

        minimum = *func(a);

        high_resolution_clock::time_point end = high_resolution_clock::now();
        long duration = duration_cast<microseconds>(end - start).count();
        iostream << minimum << "       |   Time: " << duration << "  | ArraySize: " << a.size() << endl;
    }

}

template<typename T, size_t SIZE>
void measureSelectionSort(array<T, SIZE> &a, T *(*func)(array<T, SIZE> &a), stringstream &iostream) {
    T minimum;
    for (size_t i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
                fillArrayAsc(a);
                iostream << "Result ASC : ";
                break;
            case 2:
                fillArrayDesc(a);
                iostream << "Result DESC: ";
                break;
            case 3:
                fillArrayRandom(a);
                iostream << "Result RAND: ";
                break;
        }
        clearCache();

        high_resolution_clock::time_point start = high_resolution_clock::now();

        minimum = *func(a);

        high_resolution_clock::time_point end = high_resolution_clock::now();
        long duration = duration_cast<microseconds>(end - start).count();
        iostream << minimum << "       |   Time: " << duration << "  | ArraySize: " << a.size() << endl;
    }
}

#endif //OPL_MEASUREMENT_H
