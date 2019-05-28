#include "gtest/gtest.h"
#include "seqList.h"

using namespace crb_dataStructure;

class SeqListTester : public seqList <int>, public testing::Test {
protected:
    seqList <int> intList;
    seqList <float> floatList;
    virtual void SetUp(){
        intList.insert(0, 0);
        intList.insert(1, 1);
        intList.insert(2, 2);
    }
};

TEST_F(SeqListTester, TestInsert){
    EXPECT_EQ(intList.length(), 3);
    intList.insert(3, 3);
    intList.insert(4, 4);
    intList.insert(0, 5);
    EXPECT_EQ(intList.length(), 6);
    EXPECT_EQ(intList.visit(3), 2);
    intList.insert(-1, 0);
    intList.insert(10, 0);
    displayList(intList);
}

TEST_F(SeqListTester, TestRemove){
    intList.remove(1);
    EXPECT_EQ(intList.length(), 2);
    EXPECT_EQ(intList.visit(1), 2);
    intList.remove(10);
    displayList(intList);
}

TEST_F(SeqListTester, TestDoubleSpace){
    for (int i = 0; i < 20; ++i){
        intList.insert(0, 0);
    }
    EXPECT_EQ(intList.length(), 23);
    displayList(intList);
}

TEST_F(SeqListTester, TestSearch){
    floatList.insert(0, 0.0f);
    floatList.insert(1, 1.0f);
    floatList.insert(2, 2.0f);
    EXPECT_EQ(floatList.search(2.0f), 2);
    EXPECT_EQ(floatList.search(3.0f), -1);
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

