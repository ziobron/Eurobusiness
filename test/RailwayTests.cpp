#include <gtest/gtest.h>
#include "Railway.hpp"
#include "Field.hpp"

struct RailwayTests : public ::testing::Test
{
    std::shared_ptr<Property> railwayWest = std::make_shared<Railway>("West", 250);
};

TEST_F(RailwayTests, check_if_railwayWest_has_name_West_and_Railway)
{
    ASSERT_EQ("Railway", railwayWest->getName());
    ASSERT_EQ("West", std::dynamic_pointer_cast<Railway>(railwayWest)->getNameRailway());
}

TEST_F(RailwayTests, check_if_railwayWest_has_purchasePrice_250)
{
    ASSERT_EQ(250, railwayWest->getPurchasePrice());
}

