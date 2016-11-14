#include <gtest/gtest.h>

#include "../src/algorithms/SelectionSort.h"

using namespace std;

class SelectionSortTest : public ::testing::Test {

public:
    SelectionSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~SelectionSortTest() {}
};


// SELECTION SORT TESTS
TEST_F(SelectionSortTest, selectionSortTest_Integer) {
    array<int, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAnArray(arr);
    for (int i = 0,; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], i + 1);
    }

    arr = {8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAnArrayWithJumpCacheline(arr);
    for (int i = 0,; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], i + 1);
    }

    arr = {8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAnArrayWithPrefetch(arr);
    for (int i = 0,; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], i + 1);
    }
}


TEST_F(SelectionSortTest, selectionSortTest_Double) {
    array<double, 8> arr = {8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAnArray(arr);
    double k = 1;
    for (int i = 0,; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], k);
        k += 1;
    }

    arr = {8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAnArrayWithJumpCacheline(arr);
    k = 1;
    for (int i = 0,; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], k);
        k += 1;
    }

    arr = {8, 7, 6, 5, 4, 3, 2, 1};
    selectionSortAnArrayWithPrefetch(arr);
    k = 1;
    for (int i = 0,; i < 8; i++) {
        GTEST_ASSERT_EQ(arr[i], k);
        k += 1;
    }
}


TEST_F(SelectionSortTest, selectionSortTest_Char) {
    array<char, 8> arr = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    selectionSortAnArray(arr);
    GTEST_ASSERT_EQ(arr[0], 'a');
    GTEST_ASSERT_EQ(arr[7], 'h');

    arr = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    selectionSortAnArrayWithJumpCacheline(arr);
    GTEST_ASSERT_EQ(arr[0], 'a');
    GTEST_ASSERT_EQ(arr[7], 'h');

    arr = {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    selectionSortAnArrayWithPrefetch(arr);
    GTEST_ASSERT_EQ(arr[0], 'a');
    GTEST_ASSERT_EQ(arr[7], 'h');
}

