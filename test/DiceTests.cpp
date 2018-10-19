#include <gtest/gtest.h>
#include "Dice.hpp"

struct DiceTest : public ::testing::Test
{
    Dice dice;
};

TEST_F(DiceTest, check_if_throwIt_returns_number_from_the_range_from_1_to_12)
{
    int throw_ = dice.throwIt();
    ASSERT_TRUE(throw_ <= 12 && throw_ >= 1);
}
