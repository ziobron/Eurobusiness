#include <gtest/gtest.h>
#include "Cards.hpp"
#include <stdexcept>

struct CardsTests : public ::testing::Test
{
    json dataJson = R"({"2" : "Wracasz do Madrytu."})"_json;
    Cards redCards{CardsColor::RED, dataJson};
};

TEST_F(CardsTests, check_if_color_of_redCards_is_red)
{
    ASSERT_EQ(CardsColor::RED, redCards.getColor());
}

TEST_F(CardsTests, check_if_call_getOneCard_out_of_range_will_throw_exception)
{
    ASSERT_ANY_THROW(redCards.getOneCard(16));
}

TEST_F(CardsTests, check_if_2th_card_is_Wracasz_do_Madrytu)
{
    ASSERT_EQ("Wracasz do Madrytu.", redCards.getOneCard(2));
}
