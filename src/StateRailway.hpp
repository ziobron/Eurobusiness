#pragma once

#include "State.hpp"

class StateRailway : public State
{
public:
    virtual int getPriceStamp() = 0; 
};

class NoRailway : public StateRailway
{
public:
    int getPriceStamp() { return 1;}
};
