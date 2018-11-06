#include "Dice.hpp"
#include "gmock/gmock.h"

struct DiceMock : public DiceI
{
    MOCK_METHOD0(throwIt, int());
};
