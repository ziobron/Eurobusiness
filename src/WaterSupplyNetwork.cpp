#include "WaterSupplyNetwork.hpp"
#include "StateRailwayAndWaterSN.hpp"

WaterSupplyNetwork::WaterSupplyNetwork(const std::string & name, int purchasePrice) :
    Property(name, purchasePrice)
{
    state_ = std::make_shared<YouCanBuy>();
}
