#include <gtest/gtest.h>
#include "Property.hpp"
#include "Player.hpp"

struct PropertyTests : public ::testing::Test
{
    Property vienna{"Vienna"};
};

TEST_F(PropertyTests, check_if_value_getName_is_Vienna)
{
    ASSERT_EQ("Vienna", vienna.getName());
}

TEST_F(PropertyTests, check_if_initial_value_getOwner_is_nullptr)
{
    ASSERT_EQ(nullptr, vienna.getOwner());
}

TEST_F(PropertyTests, check_if_value_getPurchasePrice_is_700)
{
    ASSERT_EQ(700, vienna.getPurchasePrice());
}

TEST_F(PropertyTests, set_playerRed_as_owner_property_and_doOn_playerBlue_then_check_if_playerBlue_has_2988_money_and_palyerRed_has_3012_money)
{
    std::shared_ptr<Player> playerRed = std::make_shared<Player>(Color::Red);
    std::shared_ptr<Player> playerBlue = std::make_shared<Player>(Color::Blue);
    vienna.setOwner(playerRed);
    vienna.doOn(playerBlue);
    ASSERT_EQ(2988, playerBlue->getMoney());
    ASSERT_EQ(3012, playerRed->getMoney());
}

TEST_F(PropertyTests, set_owner_on_property_and_check_if_owner_of_property_is_the_same)
{
    std::shared_ptr<Player> player = std::make_shared<Player>(Color::Red);
    vienna.setOwner(player);
    ASSERT_EQ(player, vienna.getOwner());
}

TEST_F(PropertyTests, set_owner_player_on_property_and_made_doOn_player_then_amountOfMoney_should_be_3000)
{
    std::shared_ptr<Player> player = std::make_shared<Player>(Color::Red);
    vienna.setOwner(player);
    vienna.doOn(player);
    ASSERT_EQ(3000, player->getMoney());
}
