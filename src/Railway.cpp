#include "Railway.hpp"
#include "StateRailway.hpp"

Railway::Railway(const std::string & nameRailway, int purchasePrice) :
    Property("Railway", purchasePrice),
    nameRailway_(nameRailway)
{
    state_ = std::make_shared<YouCanBuy>();
}

void Railway::doOn(PlayerPtr player) 
{

}

std::string Railway::getNameRailway() const
{
    return nameRailway_;
}
