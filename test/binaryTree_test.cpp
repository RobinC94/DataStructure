#include "gtest/gtest.h"
#include "binaryTree.h"

using namespace crb_dataStructure;

class BinaryTreeTester : public testing::Test {
protected:
    static void SetUpTestCase() {
        charTree_ = new BinaryTree<char>();
    }

    static void TearDownTestCase() {
        delete charTree_;
    }

    static BinaryTree<char> *charTree_;
};

BinaryTree<char> *BinaryTreeTester::charTree_ = nullptr;

TEST_F(BinaryTreeTester, TestCreateTree) {
    BinaryTree<int> intTree;
    intTree.creatTree(0);
    intTree.preOrder();
}

TEST_F(BinaryTreeTester, TestMakeTree) {
    auto &charTree = *charTree_;
    BinaryTree<char> t1('M'), t2('@'), t3('0'), t4;
    t4.makeTree('Y', t2, t3);
    charTree.makeTree('a', t1, t4);
    EXPECT_EQ(charTree.size(), 5);
    EXPECT_EQ(charTree.height(), 3);
}

TEST_F(BinaryTreeTester, TestDisplay) {
    auto &charTree = *charTree_;
    charTree.preOrder();
    charTree.postOrder();
    charTree.midOrder();
}

TEST_F(BinaryTreeTester, TestDelete) {
    auto &charTree = *charTree_;
    charTree.delRight();
    EXPECT_EQ(charTree.size(), 2);
    EXPECT_EQ(charTree.height(), 2);
    charTree.delLeft();
    EXPECT_EQ(charTree.size(), 1);
    EXPECT_EQ(charTree.height(), 1);
    charTree.clear();
    EXPECT_EQ(charTree.size(), 0);
    EXPECT_EQ(charTree.height(), 0);
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}