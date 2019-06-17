#include "gtest/gtest.h"
#include "seqList.h"
#include "linkList.h"
#include "doubleLinkList.h"

using namespace crb_dataStructure;

class ListTester : public testing::Test {
protected:
    static void SetUpTestCase() {
        intList_ = new seqList<int>();
        charList_ = new linkList<char>();
        doubleList_ = new doubleLinkList<double>();
    }

    static void TearDownTestCase() {
        delete intList_;
        delete charList_;
        delete doubleList_;
    }

    static seqList<int> *intList_;
    static linkList<char> *charList_;
    static doubleLinkList<double> *doubleList_;
};

seqList<int> *ListTester::intList_ = nullptr;
linkList<char> *ListTester::charList_ = nullptr;
doubleLinkList<double> *ListTester::doubleList_ = nullptr;

TEST_F(ListTester, TestInsert) {
    auto &intList = *intList_;
    auto &charList = *charList_;
    auto &doubleList = *doubleList_;
    for (int i = 0; i < 12; ++i) {
        intList.insert(i, i);
        charList.insert(i, 'a' + i);
        doubleList.insert(i, 0.0 + i);
    }
    EXPECT_EQ(intList.length(), 12);
    EXPECT_EQ(charList.length(), 12);
    EXPECT_EQ(doubleList.length(), 12);
    intList.insert(50, 50);
    charList.insert(50, 'z');
    doubleList.insert(50, 50.0);
    displayList(intList);
    displayList(charList);
    displayList(doubleList);
}

TEST_F(ListTester, TestRemove) {
    auto &intList = *intList_;
    auto &charList = *charList_;
    auto &doubleList = *doubleList_;
    for (int i = 0; i < 3; ++i) {
        int tmp = 10 - 2 * i;
        intList.remove(tmp);
        charList.remove(tmp);
        doubleList.remove(tmp);
    }
    EXPECT_EQ(intList.length(), 9);
    EXPECT_EQ(charList.length(), 9);
    EXPECT_EQ(doubleList.length(), 9);
    intList.remove(50);
    charList.remove(50);
    doubleList.remove(50);
    displayList(intList);
    displayList(charList);
    displayList(doubleList);
}

TEST_F(ListTester, TestVisit) {
    auto &intList = *intList_;
    auto &charList = *charList_;
    auto &doubleList = *doubleList_;
    for (int i = 0; i < 3; ++i) {
        int tmp = 2 * i;
        EXPECT_EQ(intList.visit(tmp), tmp);
        EXPECT_EQ(charList.visit(tmp), 'a' + tmp);
        EXPECT_EQ(doubleList.visit(tmp), tmp);
    }
    EXPECT_EQ(intList.visit(50), -1);
    EXPECT_EQ(charList.visit(50), -1);
    EXPECT_EQ(doubleList.visit(50), -1);
}

TEST_F(ListTester, TestSearch) {
    auto &intList = *intList_;
    auto &charList = *charList_;
    auto &doubleList = *doubleList_;
    EXPECT_EQ(intList.search(5), 5);
    EXPECT_EQ(charList.search('f'), 5);
    EXPECT_EQ(doubleList.search(5.0), 5);
    EXPECT_EQ(intList.search(50), -1);
    EXPECT_EQ(charList.search('z'), -1);
    EXPECT_EQ(doubleList.search(50.0), -1);
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}