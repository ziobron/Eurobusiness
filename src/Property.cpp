#include "Property.hpp"
#include <iostream>

Property::Property(const std::string & name) :
    name_(name),
    purchasePrice_(700)
{}

int Property::getPurchasePrice() const
{
    return purchasePrice_;
}

std::string Property::getName() const
{
    return name_;
}

void Property::doOn(std::shared_ptr<Player> player)
{
    player->reduceMoney(12);
}
