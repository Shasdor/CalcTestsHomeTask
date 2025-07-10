// (C) PROTEI protei.com

#include "SimpleCalculator.h"
#include "IHistory.h"

#include <sstream>

namespace calc
{

SimpleCalculator::SimpleCalculator(IHistory& history)
    : m_history(history)
{
}

void SimpleCalculator::SetHistory(IHistory& history)
{
    m_history = history;
}

double SimpleCalculator::Add(double a, double b)
{
    double result = a + b;
    LogOperation(a, "+", b, result);
    return result;
}

double SimpleCalculator::Subtract(double a, double b)
{
    double result = a - b;
    LogOperation(a, "-", b, result);
    return result;
}

double SimpleCalculator::Multiply(double a, double b)
{
    double result = a * b;
    LogOperation(a, "*", b, result);
    return result;
}

double SimpleCalculator::Divide(double a, double b)
{
    double result = a / b;
    if (b == 0)
    {
        throw std::runtime_error("Division by zero");
    }
    LogOperation(a, "/", b, result);

    return result;
}

void SimpleCalculator::LogOperation(double a, const char* op, double b, double result)
{
    std::ostringstream oss;
    oss << a << " " << op << " " << b << " = " << result;
    m_history.AddEntry(oss.str());
}

} // namespace calc
