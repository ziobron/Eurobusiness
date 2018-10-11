#include "Player.hpp"

Player::Player(const std::string &color)
        : color_(color),
        money_(3000),
        stillInGame_(true),
        location_(0)
{}

std::string Player:: getColor(){return color_;}
int Player:: amountOfMoney(){return money_;}
bool Player:: isStillInGame(){return stillInGame_;}
int Player :: getLocation(){ return location_;}
bool Player :: ownsProperty()
{
    if(properties_.empty()) return false;
    else return true;
}