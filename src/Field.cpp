#include "Field.hpp"

Field::Field(const std::string & name) :
    name_(name)
{}

std::string Field::getName() const
{
    return name_;
}
