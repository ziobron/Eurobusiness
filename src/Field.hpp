#pragma once
#include <memory>
#include <string>

class Player;

class Field
{
public:
    virtual ~Field() = default;
    virtual void doOn(std::shared_ptr<Player> player) = 0;
    virtual std::string getName() const = 0;
};
