#include "Player.hpp"
#include <algorithm>

Player::Player(Color c)
        : color_(c),
        money_(3000),
        location_(0)
{}

Color Player::getColor() const
{
    return color_;
}

int Player::getMoney() const
{
    return money_;
}

int Player::getLocation() const
{
    return location_;
}

void Player::setLocation(const int location)
{
    location_ = location;
}

void Player::addProperty(const std::shared_ptr<Property> & property)
{
    properties_.push_back(property);
}

void Player::reduceMoney(int price)
{
    money_ -= price;
}
