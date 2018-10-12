#include <gtest/gtest.h>
#include "Player.hpp"


struct PlayerTests : public::testing::Test
{
    Player player{Color::Blue};
};

TEST_F(PlayerTests, checkIfPlayerIsCreatedWithDefaultParameters)
{
    ASSERT_EQ(Color::Blue,player.getColor());
    ASSERT_EQ(3000,player.amountOfMoney());
    ASSERT_EQ(0,player.getLocation());
    ASSERT_FALSE(player.hasAnyProperty());
}

TEST_F(PlayerTests, setLocationTo12ShouldMoveThePlayerToField12)
{
    player.setLocation(12);
    ASSERT_EQ(12,player.getLocation());
}

TEST_F(PlayerTests, addingViennaShouldCauseHavingAnyProperty)
{
    auto vienna=std::make_shared<Property>("Vienna");
    player.addProperty(vienna);
    ASSERT_TRUE(player.hasAnyProperty());
}

TEST_F(PlayerTests, addingBerlinShouldCauseHavingBerlinNotVienna)
{
    auto berlin=std::make_shared<Property>("Berlin");
    player.addProperty(berlin);
    ASSERT_FALSE(player.ownsProperty("Vienna"));
    ASSERT_TRUE(player.ownsProperty("Berlin"));
}