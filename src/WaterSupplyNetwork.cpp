#include "WaterSupplyNetwork.hpp"
#include "StateRailway.hpp"

WaterSupplyNetwork::WaterSupplyNetwork(const std::string & name, int purchasePrice) :
    Property(name, purchasePrice)
{
    state_ = std::make_shared<YouCanBuy>();
}
