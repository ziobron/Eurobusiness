#include "Board.hpp"

int Board::getNumberOfFields() const noexcept
{
    return numberOfFields;
}

void Board::setField(const int& field_) noexcept // in the future it will be depend on the dice
{
    field = field_;
}

int Board::getField() const noexcept
{
    return field;
}

