#include <gtest/gtest.h>
#include "Property.hpp"

struct PropertyTests : public ::testing::Test
{
    Property vienna{"Vienna"};
};

TEST_F(PropertyTests, check_if_value_getName_is_Vienna)
{
    ASSERT_EQ("Vienna", vienna.getName());
}

TEST_F(PropertyTests, check_if_value_getPurchasePrice_is_700)
{
    ASSERT_EQ(700, vienna.getPurchasePrice());
}
