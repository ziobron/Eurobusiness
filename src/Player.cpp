#include "Player.hpp"

Player::Player(const std::string &color)
        : color_(color),
        money_(3000),
        location_(0)
{}

std::string Player:: getColor() const {return color_;}
int Player:: amountOfMoney() const {return money_;}
int Player :: getLocation() const { return location_;}
bool Player :: ownsProperty() const
{
    if(properties_.empty()) return false;
    else return true;
}

void Player::setLocation(const int &location)
{
    location_=location;
}

void Player :: addProperty(Property& property)
{
    properties_.push_back(property);
}
