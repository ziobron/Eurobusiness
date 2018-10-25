#include <gtest/gtest.h>
#include "Railway.hpp"
#include "Field.hpp"

struct RailwayTests : public ::testing::Test
{
    std::shared_ptr<Field> railwayWest = std::make_shared<Railway>("West");
};

TEST_F(RailwayTests, check_if_railwayWest_has_name_West_and_Railway)
{
    ASSERT_EQ("Railway", railwayWest->getName());
}

