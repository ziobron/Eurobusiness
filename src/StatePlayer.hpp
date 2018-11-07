#pragma once
#include "Player.hpp"

class StatePlayer
{
public:
    virtual ~StatePlayer() = default;
    virtual int action(int) = 0;
};

class Free : public StatePlayer
{
public:
    int action(int price) { return price; }
};

class InPrison : public StatePlayer
{
    int roundInPrison = 0;
public:
    int action(int price)
    { 
        return 0;
    }
};
