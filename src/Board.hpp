#pragma once
#include <array>
#include <vector>
#include "Field.hpp"
#include "Cards.hpp"
#include "Property.hpp"
#include "WaterSupplyNetwork.hpp"
#include <memory>
#include <json.hpp>

using FieldPtr = std::shared_ptr<Field>;
using PropertyPtr = std::shared_ptr<Property>;   
using json = nlohmann::json;

class Board
{
private:
    std::vector<FieldPtr> field_;
    std::shared_ptr<Cards> redCards_;   
    std::shared_ptr<Cards> blueCards_;   
    std::shared_ptr<WaterSupplyNetwork> waterSupplyNetwork_;   
    std::array<PropertyPtr, 28> properties_;
public:
    Board(const std::string & fileName = "../files/configData.json");
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    json readFile(const std::string & fileName);
    void setCards(json dataPacked);
    void setFieldToCards(const json & dataFields);
    FieldPtr getField(const unsigned int numberOfField) const noexcept;
    FieldPtr factoryFields(const std::string & name);
    oneCard getRedCard();
    oneCard getBlueCard();
    FieldPtr ffactoryFields(const std::string & name);
};

