#include "Dice.hpp"
#include <iostream>
#include <ctime>
#include <random>
#include <functional>

int Dice::throwIt() noexcept
{
    std::mt19937 engine(time(nullptr));
    std::uniform_int_distribution<int> distribuation(1, 12);
    auto random = std::bind(distribuation, engine);
    return random();
}



