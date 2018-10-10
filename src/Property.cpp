#include "Property.hpp"

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
