#pragma once

#include "Field.hpp"

class OrdinaryCard : public Field
{
    std::string name_;
public:
    OrdinaryCard(const std::string name);
    void doOn(PlayerPtr player) override;
    std::string getName() const;
};
