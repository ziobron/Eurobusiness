#pragma once
#include <memory>

class Player;

class Field
{
public:
    virtual ~Field() = default;
    virtual void doSomtingOn(std::shared_ptr<Player> player) = 0;
};
