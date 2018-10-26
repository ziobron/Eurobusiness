#include <gtest/gtest.h>
#include "WaterSupplyNetwork.hpp"

struct WaterSupplyNetworkTests : public ::testing::Test
{
    WaterSupplyNetwork waterSN{"Sieć wodociągów", 300};
};

TEST_F(WaterSupplyNetworkTests, check_if_getName_waterSN_is_Siec_wodociagow)
{
    ASSERT_EQ("Sieć wodociągów", waterSN.getName());
}

TEST_F(WaterSupplyNetworkTests, check_if_getPrice_waterSN_is_300)
{
    ASSERT_EQ(300, waterSN.getPurchasePrice());
}

