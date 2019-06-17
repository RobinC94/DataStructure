#include "gtest/gtest.h"
#include "hfTree.h"

using namespace crb_dataStructure;

char testChar[] = {"aeistdn"};
int testWeight[] = {10, 15, 12, 3, 4, 13, 1};
std::string expectResult[] = {"000", "01", "11", "00110", "0010", "10", "00111"};

TEST(HFTreeTester, TestHFTree) {
    hfTree<char> charTree(testChar, testWeight, 7);
    hfTree<char>::hfCode charResult[7];
    charTree.getCode(charResult);
    for (int i = 0; i < 7; ++i) {
        EXPECT_EQ(charResult[i].code, expectResult[i]);
    }
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}