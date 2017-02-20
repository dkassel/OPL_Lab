#ifndef OPL_MEASUREMENT_H
#define OPL_MEASUREMENT_H

#include "algorithms/MinimumSearch.h"
#include "algorithms/SelectionSort.h"
#include "algorithms/Quicksort.h"
#include "algorithms/Mergesort.h"
#include "algorithms/Insertionsort.h"

#include <sstream>
#include <chrono>
#include <iostream>
#include "utils/ArrayFiller.h"
#include <iostream>


using namespace std;
using namespace chrono;

const size_t MIN_TESTARRAY_SIZE = 2097152;

const size_t MAX_TESTARRAY_SIZE = 134217728*2;


template<typename T, size_t SIZE>
void measure(array<T, SIZE> &a, void (*func)(array<T, SIZE> &a), stringstream &iostream) {
    iostream << a.size() << "&";

    for (size_t i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
                fillArrayAsc(a);
                break;
            case 2:
                fillArrayDesc(a);
                break;
            case 3:
                fillArrayRandom(a);
                break;
        }
        clearCache();

        high_resolution_clock::time_point start = high_resolution_clock::now();
        func(a);
        high_resolution_clock::time_point end = high_resolution_clock::now();

        long duration = duration_cast<milliseconds>(end - start).count();//microseconds
        iostream << duration << "&";
    }
}


template<typename T, size_t SIZE>
void measure(void (*func)(array<T, SIZE> &a)) {
    array<T, SIZE> *arr = new array<T, SIZE>();
    stringstream iostream;

    iostream << arr->size() << "&";

    for (size_t i = 1; i <= 3; i++) {
        switch (i) {
            case 1:
                fillArrayAsc(*arr);
                break;
            case 2:
                fillArrayDesc(*arr);
                break;
            case 3:
                fillArrayRandom(*arr);
                break;
        }
        clearCache();

        high_resolution_clock::time_point start = high_resolution_clock::now();
        func(*arr);
        high_resolution_clock::time_point end = high_resolution_clock::now();

        long duration = duration_cast<milliseconds>(end - start).count();//microseconds
        iostream << duration << "&";
    }

    cout << iostream.str() << "\\\\\\hline" << endl;
    delete arr;
}


template<size_t SIZE>
struct TestRun {
    static void execute() {
        array<double, SIZE> *arr = new array<double, SIZE>();
        //cout << "Testrun with arraysize " << SIZE << endl;

        stringstream iostream;
        iostream << arr->size() << "&" ;

        for (size_t i = 1; i <= 3; i++) {
            switch (i) {
                case 1:
                    fillArrayAsc(*arr);
                    break;
                case 2:
                    fillArrayDesc(*arr);
                    break;
                case 3:
                    fillArrayRandom(*arr);
                    break;
            }
            clearCache();

            high_resolution_clock::time_point start = high_resolution_clock::now();
            quicksortHybrid(*arr);
            high_resolution_clock::time_point end = high_resolution_clock::now();

            long duration = duration_cast<milliseconds>(end - start).count();//microseconds
            iostream << duration << "&";
        }
        cout << iostream.str() << "\\\\\\hline" << endl << endl;
        delete arr;
        TestRun<SIZE * 2>::execute();

    }
};

template<>
struct TestRun<MAX_TESTARRAY_SIZE> {
    static void execute() {}
};


#endif //OPL_MEASUREMENT_H
