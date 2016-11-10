

#include <iostream>
#include "src/utils/ArrayFiller.h"
#include "src/utils/Timer.h"
#include "src/algorithms/MinimumSearch.h"

#include <sstream>

//const size_t SIZE = 65536;
const size_t SIZE = 65325000;
const int CACHE_SIZE = 2621440; //~20MB

using namespace std;

void clearCache() {
    array<long, CACHE_SIZE> *a = new array<long, CACHE_SIZE>();

    for (int i = 0; i < CACHE_SIZE; i++) { a->at(i) = 1L; }
    delete a;
}

int main() {
    Timer timer;
    ArrayFiller filler;
    string msgResult = "";
    //string msgType = "";
    MinimumSearch minimumSearch;
    stringstream outputstream;

    //array<double, SIZE> *arr = new array<double, SIZE>();

    cout << "-------------- Minimum search --------------"<< endl;

    for (int k = 1; k <= 3; k++) {
        switch (k) {
            case 1:
                //msgType = "-- Type: Normal --";
                outputstream << "\n-- Type: Normal --" << endl;
                break;
            case 2:
                //msgType = "-- Type: JumpCacheline --";
                outputstream << "\n-- Type: Normal --" << endl;
                break;
            case 3:
               // msgType = "-- Type: Prefetch --";
                outputstream << "\n-- Type: Normal --" << endl;
                break;
        }
        //cout << msgType << endl;

        for (int i = 1; i <= 3; i++) {
            array<int, SIZE> *arr = new array<int, SIZE>();
            int minimum;

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

            clearCache();
            timer.startTimer();

            switch (k) {
                case 1:
                    minimum = *minimumSearch.findMinimum(*arr);
                    break;
                case 2:
                    minimum = *minimumSearch.findMinimumWithJumpCacheline(*arr);
                    break;
                case 3:
                    minimum = *minimumSearch.findMinimumWithPrefetch(*arr);
                    break;
            }
            long duration = timer.stopTimer();
            outputstream << msgResult << minimum << "       |   Time: " << duration << "  | ArraySize: " << arr->size() << endl;
            delete arr;

        }
    }

    cout << outputstream.str();
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
*/

    //Chronometry chronometry;    //Timer
    //clearCache();

    // Minimumsuche Normal
    //chronometry.measureMinimumSearch(*arr);


    // Minimumsuche mit jump cacheline

    // Minimumsuche mit Prefetch


/*
    std::array<double, 16> a = {88, 45, 11, 2, 63, 5, 87, 9, 77, 1024, 5, 63, 11, 25, 88, 57};

    MinimumSearch *minimumSearch = new MinimumSearch();

    printf("Search minimum...\n");
    std::cout << minimumSearch->minimum(a) << std::endl;
    printf("Search minimum with Jump Cacheline...\n");
    std::cout << minimumSearch->findMinimumWithJumpCacheline(a) << std::endl;
    printf("End of program\n");

    delete minimumSearch;
    */

    return 0;
}





