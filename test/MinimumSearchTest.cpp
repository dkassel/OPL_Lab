#include <gtest/gtest.h>
#include <random>


#include "../src/algorithms/MinimumSearch.h"

using namespace std;

const size_t TEST_ARR_SIZE = 512;

class MinimumSearchTest : public ::testing::Test {

public:
    template<typename T, size_t TEST_ARR_SIZE>
    void fillTestArray(std::array<T, TEST_ARR_SIZE> &a);

    MinimumSearchTest() {}

    void SetUp() {}

    void TearDown() {}

    ~MinimumSearchTest() {}
};

template<typename T, size_t TEST_ARR_SIZE>
void MinimumSearchTest::fillTestArray(std::array<T, TEST_ARR_SIZE> &a) {
    std::mt19937 generator;
    generator.seed(std::random_device{}());
    std::uniform_int_distribution<int> dis(0, (TEST_ARR_SIZE - 1));

    for (size_t i = 0; i < TEST_ARR_SIZE; i++) {
        a.at(i) = generator();
    }
    a.at(dis(generator)) = std::numeric_limits<int>::min();
}

TEST_F(MinimumSearchTest, findMinimum) {
    array<int, TEST_ARR_SIZE> *a = new array<int, TEST_ARR_SIZE>();
    MinimumSearch minimumSearch;

    for (int i = 0; i < 10; i++) {
        fillTestArray(*a);
        int *min = minimumSearch.findMinimum(*a);
        GTEST_ASSERT_EQ(*min, numeric_limits<int>::min());
    }

    delete a;
}

TEST_F(MinimumSearchTest, findMinimumWithJumpCacheline) {
    array<int, TEST_ARR_SIZE> *a = new array<int, TEST_ARR_SIZE>();
    MinimumSearch minimumSearch;

    for (int i = 0; i < 10; i++) {
        fillTestArray(*a);
        int *min = minimumSearch.findMinimumWithJumpCacheline(*a);
        GTEST_ASSERT_EQ(*min, numeric_limits<int>::min());
    }

    delete a;
}


TEST_F(MinimumSearchTest, compareAlgorithms) {
    array<int, TEST_ARR_SIZE> *a = new array<int, TEST_ARR_SIZE>();
    MinimumSearch minimumSearch;

    for (int i = 0; i < 10; i++) {
        fillTestArray(*a);
        int *min1 = minimumSearch.findMinimum(*a);
        int *min2 = minimumSearch.findMinimumWithJumpCacheline(*a);
        GTEST_ASSERT_EQ(*min1, *min2);
    }

    delete a;
}


// INTEGER TEST
TEST_F(MinimumSearchTest, findIntegerMinimum) {
    //array<int, 8> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    array<int, 16> arr = {2, 15, 3, 12, 5, 1, 6, 7, 8, 10, 4, 13, 14, 16, 17, 18};
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(arr), 1);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithJumpCacheline(arr), 1);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithPrefetch(arr), 1);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumInRange(arr, 7, 15), 4);
}

// DOUBLE TEST
TEST_F(MinimumSearchTest, findDoubleMinimum) {
    array<double, 8> arr = {2.0, 3.0, 1.5, 4.0, 5.0, 6.0, 7.0, 8.0};
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(arr), 1.5);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithJumpCacheline(arr), 1.5);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithPrefetch(arr), 1.5);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumInRange(arr, 3, 7), 4.0);

}

// BOOLEAN TEST
TEST_F(MinimumSearchTest, findBoolMinimum) {
    array<bool, 8> boolArray = {true, true, false, true, false, false, false, true};
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(boolArray), false);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithJumpCacheline(boolArray), false);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithPrefetch(boolArray), false);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumInRange(boolArray, 0, 5), false);
}


// CHAR TEST
TEST_F(MinimumSearchTest, findCharMinimum) {
    array<char, 8> charArray = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i'};
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(charArray), 'a');
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithJumpCacheline(charArray), 'a');
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumWithPrefetch(charArray), 'a');
    GTEST_ASSERT_EQ(*minimumSearch.findMinimumInRange(charArray, 2, 7), 'c');
}

// REPEAT TEST
TEST_F(MinimumSearchTest, callMinimumSearchRepeated) {
    array<int, 8> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(arr), 1);
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(arr), 1);
}

// SIZE 1 ARRAY TEST
TEST_F(MinimumSearchTest, sizeOneArray) {
    array<int, 1> arr = {1};
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(arr), 1);
}

// SIZE 512 ARRAY TEST
TEST_F(MinimumSearchTest, size512Array) {
    array<int, 512> arr;
    for (int i = 10; i < arr.size() + 10; i++) {
        arr[i - 10] = i;
    }
    MinimumSearch minimumSearch;
    GTEST_ASSERT_EQ(*minimumSearch.findMinimum(arr), 10);
}


