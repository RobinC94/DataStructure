#include "gtest/gtest.h"
#include "mySort.h"

using namespace crb_dataStructure;

int array[] = {54, 27, 7, 33, 9, 93, 45, 16, 87, 3, 8, 12, 34, 66, 11, 88, 77, 44, 5, 58, 26, 36, 39, 31, 14, 23, 97,
               6};
int result[] = {3, 5, 6, 7, 8, 9, 11, 12, 14, 16, 23, 26, 27, 31, 33, 34, 36, 39, 44, 45, 54, 58, 66, 77, 87, 88, 93,
                97};

template<typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T (&expected)[size],
                                       const T (*actual)) {
    for (size_t i(0); i < size; ++i) {
        if (expected[i] != actual[i]) {
            return ::testing::AssertionFailure() << "array[" << i
                                                 << "] (" << actual[i] << ") != expected[" << i
                                                 << "] (" << expected[i] << ")";
        }
    }

    return ::testing::AssertionSuccess();
}

class MySortTester : public testing::Test {
protected:
    int *intArray;

    virtual void SetUp() {
        intArray = new int[28];
        for (int i = 0; i < 28; ++i) {
            intArray[i] = array[i];
        }
    }

    virtual void TearDown() {
        delete (intArray);
    }
};

TEST_F(MySortTester, TestInsertSort) {
    mySort<int>::simpleInsertSort(intArray, 28);
    displayArray(intArray, 28);
    EXPECT_TRUE(ArraysMatch(result, intArray));
}

TEST_F(MySortTester, TestSelectSort) {

}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}