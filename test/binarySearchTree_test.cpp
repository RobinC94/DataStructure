#include "gtest/gtest.h"
#include "binarySearchTree.h"

using namespace crb_dataStructure;

int intArray[] = {10, 8, 6, 21, 87, 56, 4, 0, 11, 3, 22, 7, 5, 34, 1, 2, 9};

class BinarySearchTreeTester: public testing::Test{
protected:
    static void SetUpTestCase(){
        intTree_ = new BinarySearchTree<int>();
    }
    static void TearDownTestCase(){
        delete intTree_;
    }

    static BinarySearchTree<int> *intTree_;
};

BinarySearchTree<int>* BinarySearchTreeTester::intTree_ = nullptr;

TEST_F(BinarySearchTreeTester, TestInsert){
    auto &intTree = *intTree_;
    EXPECT_TRUE(intTree.isEmpty());
    for (auto &i : intArray){
        intTree.insert(i);
    }
    EXPECT_FALSE(intTree.isEmpty());
    displayTree(intTree);
}

TEST_F(BinarySearchTreeTester, TestFind){
    auto &intTree = *intTree_;
    for (auto &i : intArray){
        EXPECT_TRUE(intTree.find(i));
    }
    EXPECT_FALSE(intTree.find(12));
    EXPECT_FALSE(intTree.find(12));
    EXPECT_FALSE(intTree.find(80));
}

TEST_F(BinarySearchTreeTester, TestRemove){
    auto &intTree = *intTree_;
    intTree.remove(12);
    intTree.remove(11);
    EXPECT_FALSE(intTree.find(11));
    intTree.remove(6);
    EXPECT_FALSE(intTree.find(6));
    intTree.remove(3);
    EXPECT_FALSE(intTree.find(3));
    displayTree(intTree);
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}