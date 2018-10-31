#pragma once

#include "State.hpp"

class StateRailway : public State
{
public:
    virtual int getPriceStamp() = 0; 
};

class OneRailway : public StateRailway
{
public:
    int getPriceStamp() { return 50;}
};

class TwoRailwais : public StateRailway
{
public:
    int getPriceStamp() { return 100;}
};

class ThreeRailwais : public StateRailway
{
public:
    int getPriceStamp() { return 200;}
};

class FourRailwais : public StateRailway
{
public:
    int getPriceStamp() { return 400;}
};
