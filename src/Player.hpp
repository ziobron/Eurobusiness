#pragma once

#include <string>
#include "Property.hpp"
#include "StatePlayer.hpp"

class Property;
using PropertiesPtr = std::vector<std::shared_ptr<Property>>;
using StatePlayerPtr = std::shared_ptr<StatePlayer>;

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
    StatePlayerPtr state_;
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
    int addMoney(int price);
    int getLocation() const;
    void changeLocation(const int location);
    void setLocation(const int location);
    void addProperty(const std::shared_ptr<Property> & property);
    bool doYouWantBuyThisProperty() const;
    void setState(StatePlayerPtr state);
};
