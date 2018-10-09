#include <gtest/gtest.h>
#include "Property.hpp"

struct PropertyTests : public ::testing::Test
{
    std::shared_ptr<Property> railway = std::make_shared<Railway>("West railway");
};

TEST_F(PropertyTests, check_if_inicial_value_getPriceStamp_is_50)
{
    ASSERT_EQ(50, railway->getPriceStamp());
}
