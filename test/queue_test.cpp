#include "gtest/gtest.h"
#include "seqQueue.h"
#include "linkQueue.h"

using namespace crb_dataStructure;

class QueueTester : public testing::Test {
protected:
    static void SetUpTestCase() {
        intQueue_ = new seqQueue<int>();
        charQueue_ = new linkQueue<char>();
    }

    static void TearDownTestCase() {
        delete intQueue_;
        delete charQueue_;
    }

    static seqQueue<int> *intQueue_;
    static linkQueue<char> *charQueue_;
};

seqQueue<int> *QueueTester::intQueue_ = nullptr;
linkQueue<char> *QueueTester::charQueue_ = nullptr;

TEST_F(QueueTester, TestEnqueue) {
    auto &intQueue = *intQueue_;
    auto &charQueue = *charQueue_;
    EXPECT_TRUE(intQueue.isEmpty());
    EXPECT_TRUE(charQueue.isEmpty());
    for (int i = 0; i < 26; ++i) {
        intQueue.enQueue(i);
        charQueue.enQueue('a' + i);
    }
    EXPECT_EQ(intQueue.getHead(), 0);
    EXPECT_EQ(charQueue.getHead(), 'a');
}

TEST_F(QueueTester, TestDequeue) {
    auto &intQueue = *intQueue_;
    auto &charQueue = *charQueue_;
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(intQueue.deQueue(), i);
        EXPECT_EQ(charQueue.deQueue(), 'a' + i);
    }
    intQueue.enQueue(50);
    charQueue.enQueue('0');
    EXPECT_EQ(intQueue.deQueue(), 5);
    EXPECT_EQ(charQueue.deQueue(), 'f');
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}