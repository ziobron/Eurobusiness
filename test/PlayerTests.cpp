#include <gtest/gtest.h>
#include "Player.hpp"


struct PlayerTests : public::testing::Test
{
    Player player{Color::Blue};
};

TEST_F(PlayerTests, checkIfPlayerIsCreatedWithDefaultParameters)
{
    ASSERT_EQ(Color::Blue,player.getColor());
    ASSERT_EQ(3000,player.getMoney());
    ASSERT_EQ(0,player.getLocation());
}

TEST_F(PlayerTests, setLocationTo12ShouldMoveThePlayerToField12)
{
    player.setLocation(12);
    ASSERT_EQ(12,player.getLocation());
}
