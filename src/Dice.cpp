#include "Dice.hpp"
#include <random>

void Dice::throwDice() noexcept
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    value = uniform_dist(e);
}

int Dice::getValue() const noexcept
{
    return value;
}

int Dice::operator+(const Dice& secondDice)
{
    return value + secondDice.value;
}

