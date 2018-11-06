#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Dice.hpp"
#include <vector>
#include <memory>

using VecPlayersPtr = std::vector<std::shared_ptr<Player>>;

class Eurobusiness
{
    std::shared_ptr<Board> board_;
    VecPlayersPtr vecPlayersPtr_;
    std::shared_ptr<DiceI> dice_;
public:
    Eurobusiness(int numberOfPlayers, std::shared_ptr<DiceI> dice = std::make_shared<Dice>());

    VecPlayersPtr getAllPlayers() const;
    void Play();
};
