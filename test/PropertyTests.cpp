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

TEST_F(PropertyTests, send_ptr_Player_to_method_doSomething_and_check_if_value_Player_is_2988)
{
    std::shared_ptr<Player> player = std::make_shared<Player>(Color::Red);
    vienna.doOn(player);
    ASSERT_EQ(2988, player->getMoney());
}

TEST_F(PropertyTests, set_owner_on_property_and_check_if_owner_of_property_is_the_same)
{
    std::shared_ptr<Player> player = std::make_shared<Player>(Color::Red);
    vienna.setOwner(player);
    ASSERT_EQ(player, vienna.getOwner());
}
