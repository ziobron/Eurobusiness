#include "City.hpp"

City::City(const std::string & city, const std::string & country, int purchasePrice, int priceStampNoBuilding, int priceStampOneHouse, int priceStampTwoHouses) :
    Property(city, purchasePrice),
    country_(country),
    priceStampNoBuilding_(priceStampNoBuilding),
    priceStampOneHouse_(priceStampOneHouse),
    priceStampTwoHouses_(priceStampTwoHouses)
{}

