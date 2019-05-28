#include "gtest/gtest.h"
#include "seqStack.h"

using namespace crb_dataStructure;

TEST(seqStackTester, testIntStack) {
    seqStack <int> intStack;
    intStack.push(0);
    intStack.push(1);
    intStack.push(2);
    EXPECT_EQ(intStack._top(), 2);
    EXPECT_EQ(intStack.pop(), 2);
    intStack.push(3);
    EXPECT_EQ(intStack.pop(), 3);
    EXPECT_EQ(intStack.pop(), 1);
}

TEST(seqStackTester, testCharStack){
    seqStack <char> charStack;
    EXPECT_TRUE(charStack.isEmpty());
    for (int i = 0; i < 26; ++i) {
        charStack.push('a'+i);
    }
    displayStack(charStack);
    EXPECT_EQ(charStack.pop(), 'z');
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}