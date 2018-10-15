#include "Dice.hpp"
#include <iostream>
#include <ctime>

Dice::Dice()
{
   srand(time(nullptr));
}

int Dice::throwIt() noexcept
{
    return rand() % 13 + 1;
}



