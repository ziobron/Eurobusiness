#pragma once

#include "Field.hpp"

class Railway : public Field
{
    std::string nameRailway_;
public:
    Railway(const std::string & nameRailway);
    void doOn(PlayerPtr player) override;
};
