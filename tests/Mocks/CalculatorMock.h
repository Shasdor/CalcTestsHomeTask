#pragma once

#include "../ICalculator.h"

#include <gmock/gmock.h>

class ICalculatorMock : public calc::ICalculator
{
public:
    MOCK_METHOD(double, Add, (double a, double b), (override));
    MOCK_METHOD(double, Subtract, (double a, double b), (override));
    MOCK_METHOD(double, Multiply, (double a, double b), (override));
    MOCK_METHOD(double, Divide, (double a, double b), (override));

    MOCK_METHOD(void, SetHistory, (calc::IHistory& history), (override));
};

