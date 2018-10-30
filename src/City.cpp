#include "City.hpp"
#include "StateCity.hpp"

City::City(const std::string & city, const std::string & country, int purchasePrice, int priceStampNoBuilding, int priceStampOneHouse, int priceStampTwoHouses) :
    Property(city, purchasePrice),
    country_(country),
    priceStampNoBuilding_(priceStampNoBuilding),
    priceStampOneHouse_(priceStampOneHouse),
    priceStampTwoHouses_(priceStampTwoHouses)
{
    state_ = std::make_shared<YouCanBuy>();
}


