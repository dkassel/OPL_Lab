cmake_minimum_required(VERSION 3.6)
project(opl)


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wpedantic -Werror -O3")   #comment out for rununittests
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp src/algorithms/MinimumSearch.h src/algorithms/SelectionSort.h src/utils/ArrayFiller.h src/utils/Timer.h src/algorithms/Insertionsort.h src/algorithms/Mergesort.h src/algorithms/Quicksort.h src/Measurement.h)
add_executable(opl ${SOURCE_FILES})

add_subdirectory(test)