#include <gtest/gtest.h>


#include "../src/algorithms/Mergesort.h"

using namespace std;

class MergeSortTest : public ::testing::Test {

public:
    MergeSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~MergeSortTest() {}
};


// SELECTION SORT TESTS
TEST_F(MergeSortTest, mergeSortTest_Integer) {
    array<int, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    bottomUpMergeSort(arr);

    for (int i = 0; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], i + 1);
    }
}



TEST_F(MergeSortTest, mergeSortTest_Double) {
    array<double, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    bottomUpMergeSort(arr);
    double k = 1;
    for (int i = 0; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], k);
        k += 1;
    }
}


TEST_F(MergeSortTest, mergeSortTest_Char) {
    array<char, 8> arr = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    bottomUpMergeSort(arr);
    GTEST_ASSERT_EQ(arr[0], 'a');
    GTEST_ASSERT_EQ(arr[7], 'h');
}

TEST_F(MergeSortTest, mergeSortTest_NegativeNumbers) {
    array<int, 8> arr = {-8, -7, 6, -5, 4, -3, 2, 1};
    bottomUpMergeSort(arr);
    for (int i = 1; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i-1] <= arr[i], true);
    }
}

TEST_F(MergeSortTest, mergeSortTest_BigArray) {
    array<int, 65536> arr = {};

    for (int i = 65536; i >= 0; i--) {
        arr[i] = i;
    }
    bottomUpMergeSort(arr);
    for (int i = 1; i < 65536; i++) {
        GTEST_ASSERT_EQ(arr[i-1] < arr[i], true);
    }
}
