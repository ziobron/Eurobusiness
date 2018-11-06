#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Dice.hpp"
#include <vector>
#include <memory>

using VecPlayersPtr = std::vector<std::shared_ptr<Player>>;

class Eurobusiness
{
    Board board_;
    VecPlayersPtr vecPlayersPtr_;
    Dice dice_;
public:
    Eurobusiness(int numberOfPlayers);   

    VecPlayersPtr getAllPlayers() const;
    void Play();
};
