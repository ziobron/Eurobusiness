#include "Player.hpp"

Player::Player(Color c)
        : color_(c),
        money_(3000),
        location_(0)
{}

Color Player::getColor() const {return color_;}
int Player::amountOfMoney() const {return money_;}
int Player::getLocation() const { return location_;}
bool Player::hasAnyProperty() const {return not properties_.empty();}

void Player::setLocation(const int location)
{
    location_ = location;
}

void Player::addProperty(Property& property)
{
    properties_.push_back(property);
}
