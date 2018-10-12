#include <gtest/gtest.h>
#include "Card.hpp"
#include <stdexcept>

struct CardTests : public ::testing::Test
{
    Card redCard;
};

TEST_F(CardTests, check_if_call_setJob_out_of_range_will_throw_exception)
{
    ASSERT_THROW(redCard.setJob(-9, "Cofasz się o trzy pola." ), std::exception);
}

TEST_F(CardTests, check_if_call_getJob_out_of_range_will_throw_exception)
{
    ASSERT_THROW(redCard.getJob(83), std::exception);
}

TEST_F(CardTests, set_job_3_Wracasz_do_Madrytu_check_if_value_getJob_3_return_the_same_message)
{
    redCard.setJob(3, "Wracasz do Madrytu.");
    ASSERT_EQ("Wracasz do Madrytu.", redCard.getJob(3));
}
