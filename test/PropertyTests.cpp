#include <gtest/gtest.h>
#include "Property.hpp"

struct RailwayTests : public ::testing::Test
{
    std::shared_ptr<Property> railway = std::make_shared<Railway>("West railway");
};

struct CityTests : public ::testing::Test
{
    std::shared_ptr<Property> city = std::make_shared<City>("Insbruk");
};

TEST_F(RailwayTests, check_if_inicial_value_getName_is_West_railway)
{
    ASSERT_EQ("West railway", railway->getName());
}

TEST_F(RailwayTests, check_if_value_getPurchasePrice_is_120)
{
    ASSERT_EQ(120, railway->getPurchasePrice());
}

TEST_F(RailwayTests, check_if_inicial_value_getPriceStamp_is_50)
{
    ASSERT_EQ(50, railway->getPriceStamp());
}

TEST_F(RailwayTests, change_state_to_TwoRailwais_except_value_getPriceStamp_100)
{
    railway->setState(std::make_shared<TwoRailwais>());
    ASSERT_EQ(100, railway->getPriceStamp());
}

TEST_F(RailwayTests, change_state_to_ThreeRailwais_except_value_getPriceStamp_200)
{
    railway->setState(std::make_shared<ThreeRailwais>());
    ASSERT_EQ(200, railway->getPriceStamp());
}

TEST_F(RailwayTests, change_state_to_FourRailwais_except_value_getPriceStamp_400)
{
    railway->setState(std::make_shared<FourRailwais>());
    ASSERT_EQ(400, railway->getPriceStamp());
}

TEST_F(CityTests, check_if_inicial_value_getName_is_Insbruk)
{
    ASSERT_EQ("Insbruk", city->getName());
}

TEST_F(CityTests, check_if_value_getPurchasePrice_is_700)
{
    ASSERT_EQ(700, city->getPurchasePrice());
}

TEST_F(CityTests, check_if_inicial_value_getPriceStamp_is_70)
{
    ASSERT_EQ(70, city->getPriceStamp());
}

TEST_F(CityTests, change_state_to_OneHouse_except_value_getPriceStamp_350)
{
    city->setState(std::make_shared<OneHouse>());
    ASSERT_EQ(350, city->getPriceStamp());
}

TEST_F(CityTests, change_state_to_TwoHouses_except_value_getPriceStamp_1000)
{
    city->setState(std::make_shared<TwoHouses>());
    ASSERT_EQ(1000, city->getPriceStamp());
}

TEST_F(CityTests, change_state_to_ThreeHouses_except_value_getPriceStamp_2200)
{
    city->setState(std::make_shared<ThreeHouses>());
    ASSERT_EQ(2200, city->getPriceStamp());
}

TEST_F(CityTests, change_state_to_FourHouses_except_value_getPriceStamp_2600)
{
    city->setState(std::make_shared<FourHouses>());
    ASSERT_EQ(2600, city->getPriceStamp());
}
TEST_F(CityTests, change_state_to_OneHotel_except_value_getPriceStamp_3000)
{
    city->setState(std::make_shared<OneHotel>());
    ASSERT_EQ(3000, city->getPriceStamp());
}
