#include "gtest/gtest.h"
#include "openHashTable.h"
#include "closeHashTable.h"

using namespace crb_dataStructure;

int intArray[] = {4371, 1323, 6173, 4199, 4344, 0, 9679, 1989, 1111};
char charArray[] = {'a', '4', 'F', '/', '$', '\'', 'm', 12 , 113};

class HashTableTester: public testing::Test {
protected:
    static void SetUpTestCase(){
        intTable_ = new openHashTable<int>;
        charTable_ = new closeHashTable<char>;
    }
    static void TearDownTestCase(){
        delete intTable_;
        delete charTable_;
    }

    static openHashTable<int> *intTable_;
    static closeHashTable<char> *charTable_;

};

openHashTable<int> *HashTableTester::intTable_ = nullptr;
closeHashTable<char> *HashTableTester::charTable_ = nullptr;

TEST_F(HashTableTester, TestInsert) {
    auto &intTable = *intTable_;
    auto &charTable = *charTable_;
    for (int i = 0; i < 9; ++i) {
        EXPECT_TRUE(intTable.insert(intArray[i]));
        EXPECT_TRUE(charTable.insert(charArray[i]));
    }
    EXPECT_FALSE(intTable.insert(4199));
    EXPECT_FALSE(charTable.insert('F'));
    displayHashTable(intTable);
    displayHashTable(charTable);
}

TEST_F(HashTableTester, TestFind) {
    auto &intTable = *intTable_;
    auto &charTable = *charTable_;
    for (int i = 0; i < 9; ++i) {
        EXPECT_TRUE(intTable.find(intArray[i]));
        EXPECT_TRUE(charTable.find(charArray[i]));
    }
    EXPECT_FALSE(intTable.find(2333));
    EXPECT_FALSE(charTable.find('c'));
}

TEST_F(HashTableTester, TestRemove) {
    auto &intTable = *intTable_;
    auto &charTable = *charTable_;
    for (int i = 0; i < 6; ++i) {
        EXPECT_TRUE(intTable.remove(intArray[i]));
        EXPECT_TRUE(charTable.remove(charArray[7-i]));
    }
    EXPECT_FALSE(intTable.find(0));
    EXPECT_TRUE(intTable.find(1111));
    EXPECT_FALSE(charTable.find(12));
    EXPECT_TRUE(charTable.find(113));
    displayHashTable(intTable);
    displayHashTable(charTable);
}

TEST_F(HashTableTester, TestRehash) {
    auto &charTable = *charTable_;
    displayHashTable(charTable);
    charTable.rehash();
    displayHashTable(charTable);
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}