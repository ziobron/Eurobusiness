#pragma once

#include "Property.hpp"

class City : public Property
{
    std::string country_;
public:
    City(const std::string & city, const std::string & country, int purchasePrice);
};
