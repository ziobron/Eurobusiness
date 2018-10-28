#pragma once

#include "Property.hpp"

class City : public Property
{
    std::string country_;
    int priceStampNoBuilding_;
    int priceStampOneHouse_;
    int priceStampTwoHouses_;
public:
    City(const std::string & city, const std::string & country, int purchasePrice, int priceStampNoBuilding = 70, int priceStampOneHouse = 300, int priceStampTwoHouses = 500);
};
