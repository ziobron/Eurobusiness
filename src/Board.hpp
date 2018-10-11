#pragma once
#include <vector>

using Field = int;

class Board
{
private:
    int numberOfFields {40};
    std::vector<Field> field;
public:
    Board();
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    int getNumberOfFields() const noexcept;
    int getField(const int& numberOfField) const noexcept;
};

