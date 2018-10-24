#pragma once
#include <memory>

class Player;

class Field
{
public:
    virtual ~Field() = default;
    virtual void doOn(std::shared_ptr<Player> player) = 0;
};
