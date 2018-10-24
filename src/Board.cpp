#include "Board.hpp"

Board::Board()
    : field(40)
{}

Fiield Board::getField(const unsigned int numberOfField) const noexcept
{
    return field.at(numberOfField);
}

