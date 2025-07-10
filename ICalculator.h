// (C) PROTEI protei.com

#pragma once

namespace calc
{

class IHistory;

class ICalculator
{
public:
    virtual ~ICalculator() = default;

    virtual double Add(double a, double b) = 0;
    virtual double Subtract(double a, double b) = 0;
    virtual double Multiply(double a, double b) = 0;
    virtual double Divide(double a, double b) = 0;

    virtual void SetHistory(IHistory& history) = 0;
};

} // namespace calc