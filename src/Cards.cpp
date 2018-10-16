#include "Cards.hpp"

Cards::Cards(const std::string & color, json dataPacked) :
    color_(color)
{
    for (auto it = dataPacked.begin(); it != dataPacked.end(); it++)
        collectionCards_.at(stoi(it.key())) = it.value();
}
    
std::string Cards::getColor() const
{
    return color_;
}

oneCard Cards::getOneCard(const int number) const
{
    return collectionCards_.at(number);
}
