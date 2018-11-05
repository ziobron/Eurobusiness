#pragma once

#include <string>
#include "Property.hpp"

class Property;
using PropertiesPtr = std::vector<std::shared_ptr<Property>>;

enum class Color: unsigned char{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    PINK
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
    int getMoney() const;
    void reduceMoney(int price);
    void addMoney(int price);
    int getLocation() const;
    void setLocation(const int location);
    void addProperty(const std::shared_ptr<Property> & property);
};
