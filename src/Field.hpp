#pragma once
#include <memory>
#include <string>

class Player;
using PlayerPtr = std::shared_ptr<Player>;

class Field
{
public:
    virtual ~Field() = default;
    virtual void doOn(PlayerPtr player) = 0;
    virtual std::string getName() const = 0;
};
