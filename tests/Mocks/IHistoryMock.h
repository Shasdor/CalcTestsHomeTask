
#pragma once

#include "../../IHistory.h"

#include <gmock/gmock.h>

class IHistoryMock : public calc::IHistory
{
public:
    MOCK_METHOD(void, AddEntry, (const std::string& operation), (override));
    MOCK_METHOD(std::vector<std::string>, GetLastOperations, (size_t count), (const,override));
};