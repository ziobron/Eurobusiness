#pragma once
#include <random>

class DiceI
{
public:
    virtual ~DiceI() = default;
    virtual int throwIt() = 0;
};


class Dice : public DiceI
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

    int throwIt();
};

