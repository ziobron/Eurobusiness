#pragma once
#include <vector>

using Field = int;

class Board
{
private:
    std::vector<Field> field;
public:
    Board();
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    int getField(const unsigned int numberOfField) const;
};

