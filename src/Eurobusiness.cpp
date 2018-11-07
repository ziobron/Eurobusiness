#include "Eurobusiness.hpp"
#include <stdexcept>

Eurobusiness::Eurobusiness(int numberOfPlayers)
{
    roll_ = std::make_shared<Roll>();
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");
    for (int i = 0; i < numberOfPlayers; i++)
    {
        vecPlayersPtr_.push_back(std::make_shared<Player>(static_cast<Color>(i)));
    }
}

VecPlayersPtr Eurobusiness::getAllPlayers() const
{
    return vecPlayersPtr_;
}

void Eurobusiness::Play()
{
    for (auto player : vecPlayersPtr_)
    {
        int roll = roll_->throwIt(player);
        player->changeLocation(roll);
        //FieldPtr field = board_->getField(player->getLocation());
       // field->doOn(player);
    }
}
