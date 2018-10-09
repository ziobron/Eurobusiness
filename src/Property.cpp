#include "Property.hpp"

Property::Property(const std::string & name) :
    name_(name),
    purchasePrice_(120)
{}

int Property::getPurchasePrice() const
{
    return purchasePrice_;
}

std::string Property::getName() const
{
    return name_;
}

Railway::Railway(const std::string & name) :
    Property(name),
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

int Railway::getPriceStamp(int rolls) const
{
    return stateRailway_->getPriceStamp();
}

void Railway::setState(std::shared_ptr<State> state)
{
    stateRailway_ = state;
}
