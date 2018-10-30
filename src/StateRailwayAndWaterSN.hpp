#pragma once

#include "State.hpp"

class StateRailwayAndWaterSN : public State
{
public:
    virtual int getPriceStamp() = 0; 
};

class BoughtRailway : public StateRailwayAndWaterSN
{
public:
    int getPriceStamp() { return 1;}
};

class BoughtWaterSN : public StateRailwayAndWaterSN
{
public:
    int getPriceStamp() { return 1;}
};

class BoughtRailwayAndWaterSN : public StateRailwayAndWaterSN
{
public:
    int getPriceStamp() { return 1;}
};
