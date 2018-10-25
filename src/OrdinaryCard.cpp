#include "OrdinaryCard.hpp"

OrdinaryCard::OrdinaryCard(const sttd:string name) :
    name_(name)
{}

void OrdinaryCard::doOn(Player player)
{
}

std::string getName() const
{
    return name_;
}
