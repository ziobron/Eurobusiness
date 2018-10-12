#pragma once
#include <string>
#include <array>

class Card
{
    std::array<std::string, 16> jobs_;
public:
    void setJob(const int number, const std::string & job);
    std::string getJob(const int number) const;
};
