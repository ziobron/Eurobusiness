#include "Cards.hpp"

Cards::Cards(json dataPacked) :
    color_(dataPacked.begin().key())
{
    for (json::iterator it = dataPacked.at(color_).begin(); it != dataPacked.at(color_).end(); it++)
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
