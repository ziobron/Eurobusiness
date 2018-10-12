#include <gtest/gtest.h>
#include "Player.hpp"
#include "Property.hpp"

struct PlayerTests : public ::testing::Test
{
    Player player{Color::Blue};
};

TEST_F(PlayerTests, check_if_player)
{
    ASSERT_EQ(Color::Blue,player.getColor());
    ASSERT_EQ(3000,player.amountOfMoney());
    ASSERT_EQ(0,player.getLocation());
    ASSERT_FALSE(player.hasAnyProperty());
}

TEST_F(PlayerTests, check_if_location_sets_properly)
{
    player.setLocation(12);
    ASSERT_EQ(12,player.getLocation());
}

TEST_F(PlayerTests, check_if_properties_sets_properly)
{
    Property vienna{"Vienna"};
    player.addProperty(vienna);
    ASSERT_TRUE(player.hasAnyProperty());
}

TEST_F(PlayerTests, check_if_owns_vienna)
{
    Property berlin{"Berlin"};
    player.addProperty(berlin);
    ASSERT_FALSE(player.ownsProperty("Vienna"));
    ASSERT_TRUE(player.ownsProperty("Berlin"));
}