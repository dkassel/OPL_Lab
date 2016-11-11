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
TEST_F(SelectionSortTest, selectionSortTest_Normal) {
    array<int, 8> arr = {2, 6, 1, 4, 5, 3, 8, 7};
    SelectionSort sort;
    sort.selectionSortAnArray(arr, sort.normal);
    GTEST_ASSERT_EQ(arr[0], 1);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4);
    GTEST_ASSERT_EQ(arr[4], 5);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8);
}

TEST_F(SelectionSortTest, selectionSortTest_Prefetch) {
    array<int, 8> arr = {2, 6, 1, 4, 5, 3, 8, 7};
    SelectionSort sort;
    sort.selectionSortAnArray(arr, sort.prefetch);
    GTEST_ASSERT_EQ(arr[0], 1);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4);
    GTEST_ASSERT_EQ(arr[4], 5);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8);
}

TEST_F(SelectionSortTest, SelectionSortTest_Cachelinejump) {
    array<int, 8> arr = {2, 6, 1, 4, 5, 3, 8, 7};
    SelectionSort sort;
    sort.selectionSortAnArray(arr, sort.cachelinejump);
    GTEST_ASSERT_EQ(arr[0], 1);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4);
    GTEST_ASSERT_EQ(arr[4], 5);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8);
}

