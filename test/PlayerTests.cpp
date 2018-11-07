#include <gtest/gtest.h>
#include "Player.hpp"


struct PlayerTests : public::testing::Test
{
    Player player{Color::BLUE};
};

TEST_F(PlayerTests, checkIfPlayerIsCreatedWithDefaultParameters)
{
    ASSERT_EQ(Color::BLUE, player.getColor());
    ASSERT_EQ(3000,player.getMoney());
    ASSERT_EQ(0,player.getLocation());
}

TEST_F(PlayerTests, setLocationTo12ShouldMoveThePlayerToField12)
{
    player.changeLocation(12);
    ASSERT_EQ(12,player.getLocation());
}

TEST_F(PlayerTests, setLocationTo40ShouldMoveThePlayerToField0)
{
    player.changeLocation(40);
    ASSERT_EQ(0,player.getLocation());
}

TEST_F(PlayerTests, check_if_player_pass_start_his_money_increased)
{
    player.changeLocation(40);
    ASSERT_EQ(3400,player.getMoney());
}

TEST_F(PlayerTests, check_if_player_go_to_prison_and_invoke_addMoney_then_his_money_dont_increased)
{
    player.setState(std::make_shared<InPrison>());
    player.addMoney(30);
    ASSERT_EQ(3000,player.getMoney());
}
