#pragma once
#include <random>

class Dice
{
private:
    std::random_device device;
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribuation;
public:
    Dice();
    ~Dice() = default;
    Dice(const Dice&) = delete;
    Dice(Dice&&) = delete;
    Dice& operator=(const Dice&) = delete;
    Dice& operator=(Dice&&) = delete;

    int throwIt() noexcept;
};

