#include "Cards.hpp"

Cards::Cards(CardsColor color, json dataPacked) :
    color_(color)
{
    for (auto it = dataPacked.begin(); it != dataPacked.end(); it++)
        collectionCards_.at(stoi(it.key())) = it.value();
}

Cards::Cards(CardsColor color, const std::string & name) :
    Field(name),
    color_(color)
{
    collectionCards_.at(0) = name;
}
    
CardsColor Cards::getColor() const
{
    return color_;
}

oneCard Cards::getOneCard(const int number) const
{
    return collectionCards_.at(number);
}

void Cards::doOn(std::shared_ptr<Player> player)
{

}

