#include <gtest/gtest.h>
#include "City.hpp"

struct CityTests : public ::testing::Test
{
    std::shared_ptr<Property> berlin = std::make_shared<City>("Berlin","Germany", 200);
};

TEST_F(CityTests, check_if_berlin_has_name_Berlin_and_Germany)
{
    ASSERT_EQ("Berlin", berlin->getName());
//    ASSERT_EQ("Germany", std::dynamic_pointer_cast<City>(berlin)->getNameRailway());
}

TEST_F(CityTests, check_if_berlin_has_purchasePrice_200)
{
    ASSERT_EQ(200, berlin->getPurchasePrice());
}

