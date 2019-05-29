#include "gtest/gtest.h"
#include "seqStack.h"
#include "linkStack.h"

using namespace crb_dataStructure;

class StackTester: public testing::Test {
protected:
    static void SetUpTestCase(){
        intStack_ = new seqStack<int>();
        charStack_ = new linkStack<char>();
    }
    static void TearDownTestCase(){
        delete intStack_;
        delete charStack_;
    }

    static seqStack<int> *intStack_;
    static linkStack<char> *charStack_;
};

seqStack<int>* StackTester::intStack_ = nullptr;
linkStack<char>* StackTester::charStack_ = nullptr;

TEST_F(StackTester, TestStack){
    auto &intStack = *intStack_;
    auto &charStack = *charStack_;
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}