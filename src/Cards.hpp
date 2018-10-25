#pragma once
#include <json.hpp>
#include <array>
#include "Field.hpp"

using json = nlohmann::json;
using oneCard = std::string;

enum class CardsColor
{
    RED,
    BLUE
};

class Cards : public Field
{
    CardsColor color_;
    std::array<oneCard, 16> collectionCards_;
public:
    Cards() = delete;
    Cards(const Cards &) = delete;
    Cards(Cards &&) = delete;
    Cards & operator=(const Cards &) = delete;
    Cards & operator=(Cards &&) = delete;
    ~Cards() = default;
    Cards(CardsColor color, json dataPacked);
    Cards(CardsColor color, const std::string & name);

    oneCard getOneCard(const int number) const;
    CardsColor getColor() const;
    void doOn(std::shared_ptr<Player> player) override;
    std::string getName() const override;
};
