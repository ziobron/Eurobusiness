#include "Railway.hpp"
#include "StateRailway.hpp"

Railway::Railway(const std::string & name, int purchasePrice) :
    Property(name, purchasePrice)
{
    state_ = std::make_shared<YouCanBuy>();
}

void Railway::doOn(PlayerPtr player) 
{

}

