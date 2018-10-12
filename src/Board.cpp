#include "Board.hpp"
#include <iostream>
#include <exception>

Board::Board()
    : field(40)
{}

int Board::getField(const unsigned int numberOfField) const
{
    if(numberOfField <= 40)
        return field[numberOfField];
    else throw std::out_of_range("Board has only 40 fields");
}

