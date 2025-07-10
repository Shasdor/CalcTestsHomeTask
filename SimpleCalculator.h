// (C) PROTEI protei.com

#pragma once

#include "ICalculator.h"

namespace calc
{

class SimpleCalculator : public ICalculator
{
public:
    explicit SimpleCalculator(IHistory& history);

    void SetHistory(IHistory& history) override;

    double Add(double a, double b) override;
    double Subtract(double a, double b) override;
    double Multiply(double a, double b) override;
    double Divide(double a, double b) override;

private:
    void LogOperation(double a, const char* op, double b, double result);

    IHistory& m_history;
};

} // namespace calc