#include "Card.hpp"

void Card::setJob(int number, const std::string & job)
{
    jobs_.at(number) = job;
}

std::string Card::getJob(int number) const
{
    return jobs_.at(number);
}
