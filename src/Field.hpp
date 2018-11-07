#pragma once
#include <memory>
#include <string>

class Player;
using PlayerPtr = std::shared_ptr<Player>;

class Field
{
    std::string name_;
public:
    Field() = delete;
    Field(const Field &) = delete;
    Field(Field &&) = delete;
    Field& operator=(const Field &) = delete;
    Field& operator=(Field &&) = delete;
    Field(const std::string & name);
    virtual ~Field() = default;
    
    virtual void doOn(PlayerPtr player) = 0;
    std::string getName() const;
};
