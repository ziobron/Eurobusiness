#pragma once
#include <vector>
#include "Field.hpp"
#include <memory>

using Fiield = std::shared_ptr<Field>;

class Board
{
private:
    std::vector<Fiield> field;
public:
    Board();
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    Fiield getField(const unsigned int numberOfField) const noexcept;
};

