#include "Dice.hpp"

Dice::Dice()
    : device()
    , generator(device())
    , distribuation(1,6)
{}

int Dice::throwIt()
{
   return distribuation(generator);
}

