#include <gtest/gtest.h>

#include "../src/algorithms/Insertionsort.h"


using namespace std;

class InsertionSortTest : public ::testing::Test {

public:
    InsertionSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~InsertionSortTest() {}

};


TEST_F(InsertionSortTest, InsertSortTest_Integer) {
    array<int, 8> arr = {2, 6, 1, 4, 5, 3, 8, 7};
    insertionSortOnArray(arr);
    GTEST_ASSERT_EQ(arr[0], 1);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4);
    GTEST_ASSERT_EQ(arr[4], 5);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8);
}

TEST_F(InsertionSortTest, InsertSortTest_Double) {
    array<double, 8> arr = {2.0, 3.0, 1.5, 4.1, 4.3, 6.0, 7.0, 8.3};
    insertionSortOnArray(arr);
    GTEST_ASSERT_EQ(arr[0], 1.5);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4.1);
    GTEST_ASSERT_EQ(arr[4], 4.3);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8.3);
}

// BOOLEAN TEST
TEST_F(InsertionSortTest, InsertSortTest_Bool) {
    array<bool, 8> boolArray = {true, true, false, true, false, false, false, true};
    insertionSortOnArray(boolArray);
    GTEST_ASSERT_EQ(boolArray[0], false);
    GTEST_ASSERT_EQ(boolArray[1], false);
    GTEST_ASSERT_EQ(boolArray[2], false);
    GTEST_ASSERT_EQ(boolArray[3], false);
    GTEST_ASSERT_EQ(boolArray[4], true);
    GTEST_ASSERT_EQ(boolArray[5], true);
    GTEST_ASSERT_EQ(boolArray[6], true);
    GTEST_ASSERT_EQ(boolArray[7], true);
}


// CHAR TEST
TEST_F(InsertionSortTest, InsertSortTest_Char) {
    array<char, 8> charArray = {'b', 'a', 'c', 'f', 'd', 'e', 'h', 'i'};
    insertionSortOnArray(charArray);
    GTEST_ASSERT_EQ(charArray[0], 'a');
    GTEST_ASSERT_EQ(charArray[1], 'b');
    GTEST_ASSERT_EQ(charArray[2], 'c');
    GTEST_ASSERT_EQ(charArray[3], 'd');
    GTEST_ASSERT_EQ(charArray[4], 'e');
    GTEST_ASSERT_EQ(charArray[5], 'f');
    GTEST_ASSERT_EQ(charArray[6], 'h');
    GTEST_ASSERT_EQ(charArray[7], 'i');
}


TEST_F(InsertionSortTest, InsertSortTest_Integer_Prefetch) {
    array<int, 8> arr = {2, 6, 1, 4, 5, 3, 8, 7};
    insertionSortWithPrefetch(arr);
    GTEST_ASSERT_EQ(arr[0], 1);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4);
    GTEST_ASSERT_EQ(arr[4], 5);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8);
}

TEST_F(InsertionSortTest, InsertSortTest_Double_Prefetch) {
    array<double, 8> arr = {2.0, 3.0, 1.5, 4.1, 4.3, 6.0, 7.0, 8.3};
    insertionSortWithPrefetch(arr);
    GTEST_ASSERT_EQ(arr[0], 1.5);
    GTEST_ASSERT_EQ(arr[1], 2);
    GTEST_ASSERT_EQ(arr[2], 3);
    GTEST_ASSERT_EQ(arr[3], 4.1);
    GTEST_ASSERT_EQ(arr[4], 4.3);
    GTEST_ASSERT_EQ(arr[5], 6);
    GTEST_ASSERT_EQ(arr[6], 7);
    GTEST_ASSERT_EQ(arr[7], 8.3);
}

// BOOLEAN TEST
TEST_F(InsertionSortTest, InsertSortTest_Bool_Prefetch) {
    array<bool, 8> boolArray = {true, true, false, true, false, false, false, true};
    insertionSortWithPrefetch(boolArray);
    GTEST_ASSERT_EQ(boolArray[0], false);
    GTEST_ASSERT_EQ(boolArray[1], false);
    GTEST_ASSERT_EQ(boolArray[2], false);
    GTEST_ASSERT_EQ(boolArray[3], false);
    GTEST_ASSERT_EQ(boolArray[4], true);
    GTEST_ASSERT_EQ(boolArray[5], true);
    GTEST_ASSERT_EQ(boolArray[6], true);
    GTEST_ASSERT_EQ(boolArray[7], true);
}


// CHAR TEST
TEST_F(InsertionSortTest, InsertSortTest_Char_Prefetch) {
    array<char, 8> charArray = {'b', 'a', 'c', 'f', 'd', 'e', 'h', 'i'};
    insertionSortWithPrefetch(charArray);
    GTEST_ASSERT_EQ(charArray[0], 'a');
    GTEST_ASSERT_EQ(charArray[1], 'b');
    GTEST_ASSERT_EQ(charArray[2], 'c');
    GTEST_ASSERT_EQ(charArray[3], 'd');
    GTEST_ASSERT_EQ(charArray[4], 'e');
    GTEST_ASSERT_EQ(charArray[5], 'f');
    GTEST_ASSERT_EQ(charArray[6], 'h');
    GTEST_ASSERT_EQ(charArray[7], 'i');
}

TEST_F(InsertionSortTest,InsertSortTest_BigArray) {
    array<int, 32768> arr = {};

    for (int i = 32768; i >= 0; i--) {
        arr[i] = i;
    }
    insertionSortOnArray(arr);
    for (int i = 1; i < 32768; i++) {
        GTEST_ASSERT_EQ(arr[i-1] < arr[i], true);
    }
}

TEST_F(InsertionSortTest, InsertSortTest_BigArray_Prefetch) {
    array<int, 32768> arr = {};

    for (int i = 32768; i >= 0; i--) {
        arr[i] = i;
    }
    insertionSortWithPrefetch(arr);
    for (int i = 1; i < 32768; i++) {
        GTEST_ASSERT_EQ(arr[i-1] < arr[i], true);
    }
}