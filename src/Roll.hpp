#pragma once

#include "Dice.hpp"
#include "Player.hpp"


class Roll
{
    std::shared_ptr<DiceI> dice_;
public:
    Roll(std::shared_ptr<DiceI> dice = std::make_shared<Dice>());
    int throwIt(PlayerPtr player);
};
