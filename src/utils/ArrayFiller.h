//
// Created by Daniel on 03.11.2016.
//

#ifndef OPL_ARRAYFILLER_H
#define OPL_ARRAYFILLER_H

#include <random>
#include <array>

using namespace std;

class ArrayFiller {
public:
    template<typename T, size_t SIZE>
    void fillArrayAsc(array<T, SIZE> &a) {
        for (size_t i = 1; i <= SIZE; i++) {
            a[i - 1] = (T) i;
        }
    }

    template<typename T, size_t SIZE>
    void fillArrayDesc(array<T, SIZE> &a) {
        for (size_t i = SIZE; i > 0; i--) {
            a[i - 1] = (T) i;
        }
    }

    template<typename T, size_t SIZE>
    void fillArrayRandom(array<T, SIZE> &a) {
        mt19937 generator;
        generator.seed(random_device{}());

        for (size_t i = 0; i < SIZE; i++) {
            a[i] = (T) generator();
        }
    }


};

#endif //OPL_ARRAYFILLER_H
