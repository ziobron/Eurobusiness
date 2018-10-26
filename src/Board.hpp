#pragma once
#include <vector>
#include "Field.hpp"
#include "Cards.hpp"
#include "Cards.hpp"
#include <memory>
#include <json.hpp>

using FieldPtr = std::shared_ptr<Field>;
using json = nlohmann::json;

class Board
{
private:
    std::vector<FieldPtr> field_;
    std::shared_ptr<Cards> redCards;   
    std::shared_ptr<Cards> blueCards;   
public:
    Board();
    Board(json dataPacked);
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    json readFile(const std::string & fileName);
    FieldPtr getField(const unsigned int numberOfField) const noexcept;
    FieldPtr factoryFields(const std::string & name);
};

