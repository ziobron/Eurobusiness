#include "Board.hpp"


Board::Board()
    : field(40)
{}

int Board::getNumberOfFields() const noexcept
{
    return numberOfFields;
}

int Board::getField(const int &numberOfField) const noexcept
{
    return field[numberOfField];
}

