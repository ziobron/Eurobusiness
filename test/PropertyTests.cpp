#include <gtest/gtest.h>
#include "Property.hpp"

struct PropertyTests : public ::testing::Test
{
    std::shared_ptr<Property> railway = std::make_shared<Railway>("West railway");
};

TEST_F(PropertyTests, check_if_inicial_value_getName_is_West_railway)
{
    ASSERT_EQ("West railway", railway->getName());
}

TEST_F(PropertyTests, check_if_value_getPurchasePrice_is_120)
{
    ASSERT_EQ(120, railway->getPurchasePrice());
}

TEST_F(PropertyTests, check_if_inicial_value_getPriceStamp_is_50)
{
    ASSERT_EQ(50, railway->getPriceStamp());
}

TEST_F(PropertyTests, change_state_to_TwoRailwais_except_value_getPriceStamp_100)
{
    railway->setState(std::make_shared<TwoRailwais>());
    ASSERT_EQ(100, railway->getPriceStamp());
}

TEST_F(PropertyTests, change_state_to_ThreeRailwais_except_value_getPriceStamp_200)
{
    railway->setState(std::make_shared<ThreeRailwais>());
    ASSERT_EQ(200, railway->getPriceStamp());
}

TEST_F(PropertyTests, change_state_to_FourRailwais_except_value_getPriceStamp_400)
{
    railway->setState(std::make_shared<FourRailwais>());
    ASSERT_EQ(400, railway->getPriceStamp());
}
