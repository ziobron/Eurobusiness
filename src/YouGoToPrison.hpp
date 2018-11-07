#pragma once
#include "Field.hpp"
#include "Player.hpp"

class YouGoToPrison : public Field
{
    int prisonField_;
public:
    YouGoToPrison(const std::string & name, int prisonField = 12);
    void doOn(PlayerPtr player); 
};
