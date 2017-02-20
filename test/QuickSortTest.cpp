#include <gtest/gtest.h>


#include "../src/algorithms/Quicksort.h"

using namespace std;

class QuickSortTest : public ::testing::Test {

public:
    QuickSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~QuickSortTest() {}
};


TEST_F(QuickSortTest, quickSortTest_Integer) {
    array<int, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(arr);

    for (int i = 0; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], i + 1);
    }
}

TEST_F(QuickSortTest, quickSortTest_BigArray) {
    array<int, 65536> arr = {};

    for (int i = 65536; i >= 0; i--) {
        arr[i] = i;
    }
    quickSort(arr);
    for (int i = 1; i < 65536; i++) {
        GTEST_ASSERT_EQ(arr[i-1] < arr[i], true);
    }
}



TEST_F(QuickSortTest, quickSortTest_Double) {
    array<double, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(arr);
    double k = 1;
    for (int i = 0; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], k);
        k += 1;
    }
}

TEST_F(QuickSortTest, quickSortTest_Char) {
    array<char, 8> arr = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    quickSort(arr);
    GTEST_ASSERT_EQ(arr[0], 'a');
    GTEST_ASSERT_EQ(arr[7], 'h');
}

TEST_F(QuickSortTest, quickSortTest_NegativeNumbers) {
    array<int, 8> arr = {-8, -7, 6, -5, 4, -3, 2, 1};
    quickSort(arr);
    for (int i = 1; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i-1] <= arr[i], true);
    }
}

// Prefetch Tests
TEST_F(QuickSortTest, quickSortTest_Integer_Hybrid) {
    array<int, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    quicksortHybrid(arr);

    for (int i = 0; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], i + 1);
    }
}

TEST_F(QuickSortTest, quickSortTest_BigArray_Hybrid) {
    array<int, 65536> arr = {};

    for (int i = 65536; i >= 0; i--) {
        arr[i] = i;
    }
    quicksortHybrid(arr);
    for (int i = 1; i < 65536; i++) {
        GTEST_ASSERT_EQ(arr[i-1] < arr[i], true);
    }
}



TEST_F(QuickSortTest, quickSortTest_Double_Hybrid) {
    array<double, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    quicksortHybrid(arr);
    double k = 1;
    for (int i = 0; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], k);
        k += 1;
    }
}


TEST_F(QuickSortTest, quickSortTest_Char_Hybrid) {
    array<char, 8> arr = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    quicksortHybrid(arr);
    GTEST_ASSERT_EQ(arr[0], 'a');
    GTEST_ASSERT_EQ(arr[7], 'h');
}

TEST_F(QuickSortTest, quickSortTest_NegativeNumbers_Hybrid) {
    array<int, 8> arr = {-8, -7, 6, -5, 4, -3, 2, 1};
    quicksortHybrid(arr);
    for (int i = 1; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i-1] <= arr[i], true);
    }
}
