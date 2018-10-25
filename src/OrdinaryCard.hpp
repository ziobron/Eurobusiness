#pragma once

#include "Field.hpp"

class OrdinaryCard : public Field
{
public:
    OrdinaryCard(const std::string & name);
    void doOn(PlayerPtr player) override;
};
