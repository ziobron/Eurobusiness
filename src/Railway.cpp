#include "Railway.hpp"

Railway::Railway(const std::string & nameRailway, int purchasePrice) :
    Property("Railway", purchasePrice),
    nameRailway_(nameRailway)
{}

void Railway::doOn(PlayerPtr player) 
{

}

std::string Railway::getNameRailway() const
{
    return nameRailway_;
}
