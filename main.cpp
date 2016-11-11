

#include <iostream>
#include "src/utils/ArrayFiller.h"
#include "src/algorithms/MinimumSearch.h"
#include <chrono>
#include "src/Measurement.h"
// #include <sstream>

const size_t SIZE = 65536;
//const size_t SIZE = 65325000;

using namespace std;
using namespace chrono;


template<typename T, size_t ARRAYSIZE>
void minimumSearch() {
    array<T, ARRAYSIZE> *arr = new array<T, ARRAYSIZE>();
    stringstream outputstream;
    outputstream << "\n-- Type: Normal --\n";
    measureMinimumSearch(*arr, findMinimum, outputstream);
    outputstream << "\n-- Type: Prefetch --\n";
    measureMinimumSearch(*arr, findMinimumWithPrefetch, outputstream);
    outputstream << "\n-- Type: Jump Cacheline --\n";
    measureMinimumSearch(*arr, findMinimumWithJumpCacheline, outputstream);


    cout << outputstream.str() << endl;
    delete arr;

}

int main() {
    //minimumSearch<double, 268435456>();
    //minimumSearch<double, 536870912>();
    minimumSearch<double, 1073741824>();
    minimumSearch<double, 2147483648>();


    return 0;


//    ArrayFiller filler;
//    string msgResult = "";
//    MinimumSearch minimumSearch;
//    stringstream outputstream;
//
//    cout << "-------------- Minimum search --------------"<< endl;
//
//    for (int k = 1; k <= 3; k++) {
//        switch (k) {
//            case 1:
//                outputstream << "\n-- Type: Normal --" << endl;
//                break;
//            case 2:
//                outputstream << "\n-- Type: Jump Cacheline --" << endl;
//                break;
//            case 3:
//                outputstream << "\n-- Type: Prefetch --" << endl;
//                break;
//        }
//
//        for (int i = 1; i <= 3; i++) {
//            array<int, SIZE> *arr = new array<int, SIZE>();
//            int minimum;
//
//            switch (i) {
//                case 1:
//                    filler.fillArrayAsc(*arr);
//                    msgResult = "Result ASC : ";
//                    break;
//                case 2:
//                    filler.fillArrayDesc(*arr);
//                    msgResult = "Result DESC: ";
//                    break;
//                case 3:
//                    filler.fillArrayRandom(*arr);
//                    msgResult = "Result RAND: ";
//                    break;
//            }
//
//            clearCache();
//            //timer.startTimer();
//            time_point<high_resolution_clock> start = system_clock::now();
//
//            switch (k) {
//                case 1:
//                    minimum = *minimumSearch.findMinimum(*arr);
//                    break;
//                case 2:
//                    minimum = *minimumSearch.findMinimumWithJumpCacheline(*arr);
//                    break;
//                case 3:
//                    minimum = *minimumSearch.findMinimumWithPrefetch(*arr);
//                    break;
//            }
//            time_point<high_resolution_clock> end = system_clock::now();
//
//            //long duration = timer.stopTimer();
//            long duration = duration_cast<microseconds>(end - start).count();
//            outputstream << msgResult << minimum << "       |   Time: " << duration << "  | ArraySize: " << arr->size() << endl;
//            delete arr;
//
//        }
//    }

    // cout << outputstream.str();
    /*

    cout << "-------------- Selection Sort --------------"<< endl;

    SelectionSort selectionSort;
    for (int k = 1; k <= 3; k++) {
        switch (k) {
            case 1:
                msgType = "-- Type: Normal --";
                break;
            case 2:
                msgType = "-- Type: JumpCacheline --";
                break;
            case 3:
                msgType = "-- Type: Prefetch --";
                break;
        }
        cout << msgType << endl;

        for (int i = 1; i <= 3; i++) {
            array<double, SIZE> *arr = new array<double, SIZE>();
            switch (i) {
                case 1:
                    filler.fillArrayAsc(*arr);
                    msgResult = "Result ASC : ";
                    break;
                case 2:
                    filler.fillArrayDesc(*arr);
                    msgResult = "Result DESC: ";
                    break;
                case 3:
                    filler.fillArrayRandom(*arr);
                    msgResult = "Result RAND: ";
                    break;
            }

            double minimum;
            clearCache();
            timer.startTimer();

            switch (k) {
                case 1:
                    selectionSort.selectionSortAnArray(*arr, selectionSort.normal);
                    break;
                case 2:
                    selectionSort.selectionSortAnArray(*arr, selectionSort.cachelinejump);
                    break;
                case 3:
                    selectionSort.selectionSortAnArray(*arr, selectionSort.prefetch);
                    break;
            }
            long duration = timer.stopTimer();
            cout << msgResult << minimum << "       |   Time: " << duration << "  | ArraySize: " << arr->size() << endl;
            delete arr;
        }
    }


     const sizearray = x;

     for i = 1; i < 5; i++
        arrsize = sizearry * x;

     arr = fillarrrayAsc;

     executeTimeMeasureMinimumSearch(&arr,

*/

}





