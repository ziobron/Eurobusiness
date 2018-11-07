#include <gtest/gtest.h>
#include "YouGoToPrison.hpp"
#include "Player.hpp"
#include <memory>

struct YouGoToPrisonTests : public ::testing::Test
{
    std::shared_ptr<Field> field  = std::make_shared<YouGoToPrison>("Idziesz do wiezenia"); 
};

TEST_F(YouGoToPrisonTests, check_field_has_name_idziesz_do_wiezenia)
{
    ASSERT_EQ("Idziesz do wiezenia", field->getName());
}

TEST_F(YouGoToPrisonTests, check_if_player_go_to_prison)
{
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    //field->doOn(player); 
    ASSERT_EQ("Idziesz do wiezenia", field->getName());
}

