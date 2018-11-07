#include <gtest/gtest.h>
#include "Roll.hpp"
#include "mock/DiceMock.hpp"
#include <memory>

using namespace ::testing;

struct RollTests : public ::testing::Test
{
    std::shared_ptr<DiceMock> diceMock = std::make_shared<DiceMock>();
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    Roll roll{diceMock};
};

TEST_F(RollTests, check_if_throwIt_return_sum_of_rolls)
{
    EXPECT_CALL(* diceMock, throwIt())
        .Times(2)
        .WillOnce(Return(1))
        .WillOnce(Return(2));
    ASSERT_EQ(3, roll.throwIt(player));
}

TEST_F(RollTests, check_if_throwIt_with_doublet_make_second_throwIt_and_return_sum_of_4_rolls)
{
    EXPECT_CALL(* diceMock, throwIt())
        .Times(4)
        .WillOnce(Return(2))
        .WillOnce(Return(2))
        .WillOnce(Return(3))
        .WillOnce(Return(5));
    ASSERT_EQ(12, roll.throwIt(player));
}

TEST_F(RollTests, check_if_throwIt_with_twice_doublet_send_palyer_to_prison)
{
    EXPECT_CALL(* diceMock, throwIt())
        .Times(4)
        .WillOnce(Return(2))
        .WillOnce(Return(2))
        .WillOnce(Return(3))
        .WillOnce(Return(3));
    roll.throwIt(player);
    ASSERT_EQ(10, player->getLocation());
}
