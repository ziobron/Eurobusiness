#include "Eurobusiness.hpp"
#include <stdexcept>

Eurobusiness::Eurobusiness(int numberOfPlayers)
{
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");
    for (int i = 0; i < numberOfPlayers; i++)
    {
        players_.push_back(std::make_shared<Player>(static_cast<Color>(i)));
    }
}



VecPlayersPtr Eurobusiness::getAllPlayers() const
{
    return players_;
}
