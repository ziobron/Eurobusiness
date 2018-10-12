#pragma once

#include <string>
#include "Property.hpp"

enum class Color: unsigned char{
    Red,
    Green,
    Blue
};

class Player{

    Color color_;
    int money_;
    int location_;
    PropertiesPtr properties_;

public:
    Player()= delete;
    Player(const Player &) = delete;
    Player(Player &&) = delete;
    ~Player() = default;
    Player & operator=(const Player &) = delete;
    Player & operator=(Player &&) = delete;

    Player(Color c);

    Color getColor() const;
    int amountOfMoney() const;
    int getLocation() const;
    void setLocation(const int location);
    void addProperty(std::shared_ptr<Property> property);
};
