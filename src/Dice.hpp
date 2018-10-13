#pragma once

class Dice
{
  private:
    int value;
public:
    Dice() = default;
    ~Dice() = default;
    Dice(const Dice&) = delete;
    Dice(Dice&&) = delete;
    Dice& operator=(const Dice&) = delete;
    Dice& operator=(Dice&&) = delete;

    void throwDice() noexcept;
    int getValue() const noexcept;
    int operator+(const Dice& secondDice);
};

