#include <string>
#include <vector>
#include "Property.hpp"

class Player{

    std::string color_;
    int money_;
    int location_;
    std::vector<Property> properties_;

public:
    Player()= delete;
    Player(const Player &) = delete;
    Player(Player &&) = delete;
    ~Player() = default;
    Player & operator=(const Player &) = delete;
    Player & operator=(Player &&) = delete;

    Player(const std::string & color);

    std::string getColor() const;
    int amountOfMoney() const;
    int getLocation() const;
    bool ownsProperty() const;

    void setLocation(const int& location);





};