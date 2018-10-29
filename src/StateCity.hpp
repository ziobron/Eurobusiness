#pragma once

#include "State.hpp"

class StateCity : public State
{
public:
    virtual int getPriceStamp() = 0;
};

class NoBuilding : public StateCity
{
public:
    int getPriceStamp();
};

class OneHouse : public StateCity
{
public:
    int getPriceStamp();
};

class TwoHouses : public StateCity
{
public:
    int getPriceStamp();
};
