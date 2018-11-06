#include "Eurobusiness.hpp"
#include <stdexcept>

Eurobusiness::Eurobusiness(int numberOfPlayers, std::shared_ptr<DiceI> dice)
{
    dice_ = dice;
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
        int throwFirst = dice_->throwIt();
        int throwSecond = dice_->throwIt();
        player->changeLocation(throwFirst + throwSecond);
        //FieldPtr field = board_->getField(player->getLocation());
       // field->doOn(player);
    }
}
