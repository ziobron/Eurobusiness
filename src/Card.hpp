#pragma once
#include <string>
#include <array>

class Card
{
    std::array<std::string, 16> jobs_;
public:
    void setJob(int number, const std::string & job);
    std::string getJob(int number) const;
};
