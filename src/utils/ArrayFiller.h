//
// Created by Daniel on 03.11.2016.
//

#ifndef OPL_ARRAYFILLER_H
#define OPL_ARRAYFILLER_H

#include <random>
#include <array>

using namespace std;
const int CACHE_SIZE = 2621440; //~20MB


template<typename T, size_t SIZE>
void fillArrayAsc(array<T, SIZE> &a) {
    for (size_t i = 1; i <= SIZE; i++) {
        a[i - 1] = (T) i;
    }
}

template<typename T, size_t SIZE>
void fillArrayDesc(array<T, SIZE> &a) {
    for (size_t i = SIZE, j = 0; i > 0; --i, ++j)
        a[j] = (T) i - 1;
}

template<typename T, size_t SIZE>
void fillArrayRandom(array<T, SIZE> &a) {
    mt19937 generator;
    generator.seed(random_device{}());

    for (size_t i = 0; i < SIZE; i++) {
        a[i] = (T) generator();
    }
}


void clearCache() {
    array<long, CACHE_SIZE> *a = new array<long, CACHE_SIZE>();

    for (int i = 0; i < CACHE_SIZE; i++) {
        a->at(i) = 1L;
    }
    delete a;
}

#endif //OPL_ARRAYFILLER_H
