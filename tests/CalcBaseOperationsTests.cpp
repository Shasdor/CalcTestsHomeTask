#include <gtest/gtest.h>
#include "../SimpleCalculator.h"
#include "../InMemoryHistory.h"
#include "Mocks/IHistoryMock.h"

using ::testing::_;
using namespace calc;

class CalculatorOperationTest : public ::testing::Test {
protected:
    void SetUp() override {
        history = std::make_unique<InMemoryHistory>();
        calc = std::make_unique<SimpleCalculator>(*history);
    }

    void TearDown() override {
        calc.reset();
        history.reset();
    }

    std::unique_ptr<InMemoryHistory> history;
    std::unique_ptr<SimpleCalculator> calc;
};


//Проверка базовых операций
TEST(SimpleCalculatorOperationTest, BaseOperations_AndLog)
{
    IHistoryMock historyMock;
    SimpleCalculator calculator(historyMock);
    calculator.SetHistory(historyMock);

    EXPECT_CALL(historyMock, AddEntry("3 + 4 = 7")).Times(1);
    ASSERT_EQ(calculator.Add(3, 4), 7);

    EXPECT_CALL(historyMock, AddEntry("7 - 4 = 3")).Times(1);
    ASSERT_EQ(calculator.Subtract(7, 4), 3);

    EXPECT_CALL(historyMock, AddEntry("5 * 4 = 20")).Times(1);    
    ASSERT_EQ(calculator.Multiply(5, 4), 20);

    EXPECT_CALL(historyMock, AddEntry("20 / 4 = 5")).Times(1);
    ASSERT_EQ(calculator.Divide(20, 4), 5);

    EXPECT_CALL(historyMock, GetLastOperations(2)).Times(1).WillOnce(testing::Return(std::vector<std::string>{"3 + 4 = 7", "7 - 4 = 3"}));

    auto lastOps = historyMock.GetLastOperations(2);
    ASSERT_EQ(lastOps.size(), 2);
    ASSERT_EQ(lastOps[0], "3 + 4 = 7");
    ASSERT_EQ(lastOps[1], "7 - 4 = 3");
}


//Дробное деление
TEST(SimpleCalculatorOperationTest, FractionalDivision_LogsAndResult)
{
    IHistoryMock historyMock;
    SimpleCalculator calculator(historyMock);

    EXPECT_CALL(historyMock, AddEntry(_)).Times(testing::AtLeast(1));
    EXPECT_NEAR(calculator.Divide(5, 2), 2.5, 0.001);
}

//Ошибка при делении на ноль
TEST(SimpleCalculatorOperationTest, Divide_ByZero_ThrowsException)
{
    IHistoryMock historyMock;
    SimpleCalculator calculator(historyMock);
    EXPECT_THROW(calculator.Divide(7,0),std::runtime_error);
}




