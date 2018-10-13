#include "Board.hpp"

Board::Board()
    : field(40)
{}

int Board::getField(const unsigned int numberOfField) const noexcept
{
    if(numberOfField < 40)
        return field[numberOfField];
}

