#pragma once

class Board
{
  private:
    int numberOfFields {40};
public:
    Board() = default;
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    int getNumberOfFields() const;
};

