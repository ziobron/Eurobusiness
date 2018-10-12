#include "Card.hpp"

void Card::setJob(const int number, const std::string & job)
{
    jobs_.at(number) = job;
}

std::string Card::getJob(const int number) const
{
    return jobs_.at(number);
}
