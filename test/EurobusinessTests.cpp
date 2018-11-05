#include <gtest/gtest.h>
#include "Eurobusiness.hpp"

struct EurobusinessTests : public ::testing::Test
{
};

TEST_F(EurobusinessTests, check_if_create_eurobusiness_with_1_player_throw)
{
    ASSERT_ANY_THROW(Eurobusiness(1));
}

TEST_F(EurobusinessTests, created_eurobusiness_with_4_players_then_check_if_number_of_players_is_the_same)
{
    Eurobusiness euro(3);
    ASSERT_EQ(3, (euro.getAllPlayers()).size() );
}

TEST_F(EurobusinessTests, created_eurobusiness_with_4_players_then_check_if_1_players_has_RED_color)
{
    Eurobusiness euro(3);
    ASSERT_EQ(Color::RED, (euro.getAllPlayers()).at(0)->getColor() );
}
