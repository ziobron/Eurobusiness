#include "City.hpp"

City::City(const std::string & city, const std::string & country, int purchasePrice) :
    Property(city, purchasePrice),
    country_(country)
{}
