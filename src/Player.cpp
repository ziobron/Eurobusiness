#include "Player.hpp"
#include <algorithm>

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

bool Player::ownsProperty(std::string propertyName) const
{
    return std::any_of(std::begin(properties_),std::end(properties_),
            [&propertyName](const Property& p){return p.getName()==propertyName;});
}
