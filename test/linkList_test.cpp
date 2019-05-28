#include <gtest/gtest.h>
#include "linkList.h"

using namespace crb_dataStructure;

TEST(linkListTester, TestIntLinkList){
    linkList<int> myLinkList;
    for (int i = 0; i < 12; ++i) {
        myLinkList.insert(i, i%4);
    }
    displayLinkList(myLinkList);
    EXPECT_EQ(myLinkList.length(), 12);
    EXPECT_EQ(myLinkList.search(3), 3);
    myLinkList.remove(3);
    EXPECT_EQ(myLinkList.search(3), 6);
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}