#include "gtest/gtest.h"
#include "seqStack.h"
#include "linkStack.h"

using namespace crb_dataStructure;

class StackTester : public testing::Test {
protected:
    static void SetUpTestCase() {
        intStack_ = new seqStack<int>();
        charStack_ = new linkStack<char>();
    }

    static void TearDownTestCase() {
        delete intStack_;
        delete charStack_;
    }

    static seqStack<int> *intStack_;
    static linkStack<char> *charStack_;
};

seqStack<int> *StackTester::intStack_ = nullptr;
linkStack<char> *StackTester::charStack_ = nullptr;

TEST_F(StackTester, TestPush) {
    auto &intStack = *intStack_;
    auto &charStack = *charStack_;
    EXPECT_TRUE(intStack.isEmpty());
    EXPECT_TRUE(charStack.isEmpty());
    for (int i = 0; i < 26; ++i) {
        intStack.push(i);
        charStack.push('a' + i);
    }
    EXPECT_EQ(intStack._top(), 25);
    EXPECT_EQ(charStack._top(), 'z');
}

TEST_F(StackTester, TestPop) {
    auto &intStack = *intStack_;
    auto &charStack = *charStack_;
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(intStack.pop(), 25 - i);
        EXPECT_EQ(charStack.pop(), 'z' - i);
    }
    intStack.push(50);
    charStack.push('0');
    EXPECT_EQ(intStack.pop(), 50);
    EXPECT_EQ(charStack.pop(), '0');
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}