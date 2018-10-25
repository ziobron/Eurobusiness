#include "Board.hpp"
#include "Property.hpp"
#include "Cards.hpp"
#include <string>

Board::Board()
    : field_(40)
{}

Board::Board(json dataPacked) :
    Board()
{
    for (auto it = dataPacked.begin(); it != dataPacked.end(); it++)
        field_.at(stoi(it.key())) = std::make_shared<Property>("Madryt");
}

FieldPtr Board::getField(const unsigned int numberOfField) const noexcept
{
    return field_.at(numberOfField);
}

FieldPtr Board::factoryFields(const std::string & name)
{
    auto pos = name.find("-");
    if (pos != std::string::npos)
    {
        return std::make_shared<Property>(name.substr(pos + 2));
    } else 
    {
        pos = name.find("Szansa");
        if (pos != std::string::npos)
            return std::make_shared<Cards>(CardsColor::RED, name.substr(pos + 8));
    }
    return nullptr;
}

