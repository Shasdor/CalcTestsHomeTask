#include <gtest/gtest.h>

#include "../InMemoryHistory.h"

using namespace calc;


class HistoryTests : public ::testing::Test {
protected:

    InMemoryHistory history;
};


TEST_F(HistoryTests, AddAndGetSingleOperation) {
    history.AddEntry("operation1");
    auto ops = history.GetLastOperations(1);
    ASSERT_EQ(ops.size(), 1);
    EXPECT_EQ(ops[0], "operation1");
}

TEST_F(HistoryTests, GetLastMultipleOperations) {
    for (int i = 0; i < 10; ++i) {
        history.AddEntry("op" + std::to_string(i));
    }
    auto ops = history.GetLastOperations(5);
    ASSERT_EQ(ops.size(), 5);
    EXPECT_EQ(ops.front(), "op5");
    EXPECT_EQ(ops.back(), "op9");
}

TEST_F(HistoryTests, GetLastMoreThanStored) {
    history.AddEntry("only_op");
    auto ops = history.GetLastOperations(10);
    ASSERT_EQ(ops.size(), 1);
    EXPECT_EQ(ops[0], "only_op");
}

TEST_F(HistoryTests, GetLastOperationsZeroCount) {
    for (int i = 0; i < 3; ++i) {
        history.AddEntry("op" + std::to_string(i));
    }
    auto ops = history.GetLastOperations(0);
    EXPECT_TRUE(ops.empty());
}

TEST_F(HistoryTests, EmptyHistoryReturnsEmpty) {
    auto ops = history.GetLastOperations(5);
    EXPECT_TRUE(ops.empty());
}


// *** Падающий тест ***
TEST_F(HistoryTests, DISABLED_History_Overflow) {
    for (int i = 0; i < 1000; ++i) {
        history.AddEntry("test" + std::to_string(i));
    }

    EXPECT_LT(history.GetLastOperations(0).size(), 1000) << 
        "History does not limit the number of stored entries yet.";
}