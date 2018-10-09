#include "Property.hpp"

Property::Property(const std::string & name, int purchasePrice) :
    name_(name),
    purchasePrice_(purchasePrice),
    owner_(nullptr)
{}

int Property::getPurchasePrice() const
{
    return purchasePrice_;
}

std::string Property::getName() const
{
    return name_;
}

void Property::setOwner(person owner)
{
    owner_ = owner;
}

person Property::getOwner() const
{
    return owner_;
}

Railwais::Railwais(const std::string & name, int purchasePrice) :
    Property(name, purchasePrice),
    stateRailway_(std::make_shared<OneRailway>())
{}

int OneRailway::getPriceStamp() const
{
    return 50;
}

int TwoRailwais::getPriceStamp() const
{
    return 100;
}

int ThreeRailwais::getPriceStamp() const
{
    return 200;
}

int FourRailwais::getPriceStamp() const
{
    return 400;
}

int NoBuilding::getPriceStamp() const
{
    return 70;
}

int OneHouse::getPriceStamp() const
{
    return 350;
}

int TwoHouses::getPriceStamp() const
{
    return 1000;
}

int ThreeHouses::getPriceStamp() const
{
    return 2200;
}

int FourHouses::getPriceStamp() const
{
    return 2600;
}

int OneHotel::getPriceStamp() const
{
    return 3000;
}

int Railwais::getPriceStamp(int rolls) const
{
    return stateRailway_->getPriceStamp();
}

void Railwais::setState(std::shared_ptr<State> state)
{
    stateRailway_ = state;
}

Railway::Railway(const std::string & name, int purchasePrice) :
    Railwais(name, purchasePrice)
{}

City::City(const std::string & name, int purchasePrice) :
    Property(name, purchasePrice),
    stateCity_(std::make_shared<NoBuilding>())
{}

int City::getPriceStamp(int rolls) const
{
    return stateCity_->getPriceStamp();
}

void City::setState(std::shared_ptr<State> state)
{
    stateCity_ = state;
}

Country::Country(const std::string & nameCountry, std::shared_ptr<Property> c1, std::shared_ptr<Property> c2, std::shared_ptr<Property> c3) :
    nameCountry_(nameCountry),
    city1_(c1),
    city2_(c2),
    city3_(c3)
{}

std::string Country::getNameCountry() const
{
    return nameCountry_;
}

std::shared_ptr<Property> Country::getCity1() const
{
    return city1_;
}

std::shared_ptr<Property> Country::getCity2() const
{
    return city2_;
}

std::shared_ptr<Property> Country::getCity3() const
{
    return city3_;
}
