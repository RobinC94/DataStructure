#include "gtest/gtest.h"
#include "seqQueue.h"

using namespace crb_dataStructure;

TEST(seqQueueTester, testDoubleQueue){
    seqQueue <double> doubleQueue;
    EXPECT_TRUE(doubleQueue.isEmpty());
    for (double i = 0.0; i < 15; ++i) {
        doubleQueue.enQueue(i);
    }
    displayQueue<double>(doubleQueue);
    EXPECT_EQ(doubleQueue.getHead(), 0.0);
    for (double i = 0.0; i < 5; ++i) {
        EXPECT_EQ(doubleQueue.deQueue(), i);
    }
}

GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}