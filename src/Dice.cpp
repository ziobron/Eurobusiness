#include "Dice.hpp"

Dice::Dice()
    : device()
    , generator(device())
    , distribuation(1,12)
{}

int Dice::throwIt() noexcept
{
   return distribuation(generator);
}



