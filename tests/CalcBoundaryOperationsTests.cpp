#include <gtest/gtest.h>
#include <cmath>

#include "../SimpleCalculator.h"
#include "../InMemoryHistory.h"

using namespace calc;

// Граничные значения
class BoundaryTest : public testing::Test {
protected:
    std::unique_ptr<InMemoryHistory> history;
    std::unique_ptr<SimpleCalculator> calculator;

    static constexpr double MAX = std::numeric_limits<double>::max();
    static constexpr double MIN = std::numeric_limits<double>::min();
    static constexpr double EPS = std::numeric_limits<double>::epsilon();

    void SetUp() override{
        history = std::make_unique<InMemoryHistory>();
        calculator = std::make_unique<SimpleCalculator> (*history);
    }

    void TearDown() override {
        calculator.reset();
        history.reset();
    }
        
};

//Верхняя граница

TEST_F(BoundaryTest, Add_MaxValue_ShouldOverflowToInfinity) {
    double result = calculator->Add(MAX, MAX);
    EXPECT_TRUE(std::isinf(result));
}

TEST_F(BoundaryTest, Subtract_MaxMinusMax_ShouldBeZero) {
    double result = calculator->Subtract(MAX, MAX);
    EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST_F(BoundaryTest, Multiply_MaxTimesTwo_ShouldOverflowToInfinity) {
    double result = calculator->Multiply(MAX, 2);
    EXPECT_TRUE(std::isinf(result));
}

TEST_F(BoundaryTest, Divide_MaxByTwo_ShouldBeHalfMax) {
    double result = calculator->Divide(MAX, 2.0);
    EXPECT_DOUBLE_EQ(result, MAX / 2.0);
}

TEST_F(BoundaryTest, Add_MaxAndEpsilon_ShouldBeMaxDueToPrecision) {
    double result = calculator->Add(MAX, EPS);
    EXPECT_DOUBLE_EQ(result, MAX);
}

//Нижняя граница
TEST_F(BoundaryTest, Add_NegativeMaxValues_ShouldOverflowToNegativeInfinity) {
    double result = calculator->Add(-MAX, -MAX);
    EXPECT_TRUE(std::isinf(result));
    EXPECT_LT(result, 0);
}

TEST_F(BoundaryTest, Subtract_NegativeMaxMinusNegativeMax_ShouldBeZero) {
    double result = calculator->Subtract(-MAX, -MAX);
    EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST_F(BoundaryTest, Multiply_NegativeMaxTimesTwo_ShouldOverflowToNegativeInfinity) {
    double result = calculator->Multiply(-MAX, 2);
    EXPECT_TRUE(std::isinf(result));
    EXPECT_LT(result, 0);
}

TEST_F(BoundaryTest, Divide_NegativeMaxByTwo_ShouldBeHalfNegativeMax) {
    double result = calculator->Divide(-MAX, 2.0);
    EXPECT_DOUBLE_EQ(result, -MAX / 2.0);
}

//Минимальное положительное число

TEST_F(BoundaryTest, Multiply_MinAndHalf_ShouldBePositive) {
    double result = calculator->Multiply(MIN, 0.5);
    EXPECT_GT(result, 0.0);
}

TEST_F(BoundaryTest, Add_MinAndEpsilon_ShouldBeGreaterThanMin) {
    double result = calculator->Add(MIN, EPS);
    EXPECT_GT(result, MIN);
}