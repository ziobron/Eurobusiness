#pragma once
#include <json.hpp>
#include <array>

using json = nlohmann::json;
using oneCard = std::string;

enum class CardsColor
{
    red,
    blue
};

class Cards
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

    oneCard getOneCard(const int number) const;
    CardsColor getColor() const;
};
