#include "Player.hpp"
#include <algorithm>
#include <iostream>

Player::Player(Color c)
        : color_(c),
        money_(3000),
        location_(0),
        state_(std::make_shared<Free>())
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

void Player::changeLocation(const int location)
{
    location_ += location;
    if (location_ >= 40)
    {
        money_ += 400;
        location_ %= 40;
    }
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

int Player::addMoney(int price)
{
    int priceToReduce = state_->action(price);
    money_ += priceToReduce;
    return priceToReduce;
}

bool Player::doYouWantBuyThisProperty() const
{
    std::cout << "Do you want buy this property?" << std::endl;
    bool answer;
    std::cin >> answer;
    return answer;
}

void Player::setState(StatePlayerPtr state)
{
    state_ = state;
}

