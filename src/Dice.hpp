#pragma once

class Dice
{
public:
    Dice();
    ~Dice() = default;
    Dice(const Dice&) = delete;
    Dice(Dice&&) = delete;
    Dice& operator=(const Dice&) = delete;
    Dice& operator=(Dice&&) = delete;

    int throwIt() noexcept;
};

