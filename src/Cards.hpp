#pragma once
#include <json.hpp>
#include <array>

using json = nlohmann::json;
using oneCard = std::string;

class Cards
{
    std::string color_;
    std::array<oneCard, 16> collectionCards_;
public:
    Cards() = delete;
    Cards(const Cards &) = delete;
    Cards(Cards &&) = delete;
    Cards & operator=(const Cards &) = delete;
    Cards & operator=(Cards &&) = delete;
    ~Cards() = default;
    Cards(json dataPacked);

    oneCard getOneCard(const int number) const;
    std::string getColor() const;
};
