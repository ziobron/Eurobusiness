#pragma once

#include "Property.hpp"

class Railway : public Property
{
    std::string nameRailway_;
public:
    Railway(const std::string & nameRailway, int purchasePrice = 100);
    std::string getNameRailway() const;
    void doOn(PlayerPtr player) override;
};
