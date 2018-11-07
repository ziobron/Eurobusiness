#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Roll.hpp"
#include <vector>
#include <memory>

using VecPlayersPtr = std::vector<std::shared_ptr<Player>>;

class Eurobusiness
{
    std::shared_ptr<Board> board_;
    VecPlayersPtr vecPlayersPtr_;
    std::shared_ptr<Roll> roll_;
    int numberOfRounds;
public:
    Eurobusiness(int numberOfPlayers);

    VecPlayersPtr getAllPlayers() const;
    void playOneRound();
    void play();
};
