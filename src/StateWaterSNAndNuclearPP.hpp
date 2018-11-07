#pragma once

#include "State.hpp"

class StateWaterSNAndNuclearPP : public State
{
public:
    virtual int getPriceStamp() = 0; 
};

class BoughtWaterSN : public StateWaterSNAndNuclearPP
{
public:
    int getPriceStamp() { return 1;}
};

class BoughtNuclearPP : public StateWaterSNAndNuclearPP
{
public:
    int getPriceStamp() { return 2;}
};

class BoughtWaterSNAndNuclearPP : public StateWaterSNAndNuclearPP
{
public:
    int getPriceStamp() { return 3;}
    int getPriceStamp(StatePtr state) { return 2*state->getPriceStamp();}
};
