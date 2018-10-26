#include "Board.hpp"
#include "Property.hpp"
#include "Cards.hpp"
#include "Railway.hpp"
#include "OrdinaryCard.hpp"
#include <string>
#include <fstream>

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
        return std::make_shared<Property>(name.substr(pos + 2));
    else 
    {
        pos = name.find("Szansa");
        if (pos != std::string::npos)
            return std::make_shared<Cards>(CardsColor::RED, name.substr(pos + 8));
        else
        {
            pos = name.find("Koleje");
            if (pos != std::string::npos)
                return std::make_shared<Railway>(name.substr(pos + 8));
        }
    }
    return std::make_shared<OrdinaryCard>(name);
}

json Board::readFile(const std::string & fileName)
{
    std::ifstream file(fileName);
    json j;
    if (file)
    {
        file >> j;
        file.close();
    }
    return j;
}

void Board::setCards(json dataPacked)
{
    redCards_ = std::make_shared<Cards>(CardsColor::RED, dataPacked["cards"]["red"]);
    blueCards_ = std::make_shared<Cards>(CardsColor::BLUE, dataPacked["cards"]["blue"]);
}

oneCard Board::getRedCard()
{
    return redCards_->getOneCard(0);
}

oneCard Board::getBlueCard()
{
    return blueCards_->getOneCard(0);
}

void Board::setFieldToCards(const json & dataPacked)
{
    for (auto it = dataPacked["fields"].begin(); it != dataPacked["fields"].end(); it++)
        field_.at(stoi(it.key())) = ffactoryFields(it.value());
}

FieldPtr Board::ffactoryFields(const std::string & name)
{
    if (name == "Szansa (czerwona)")
        return redCards_;
    else if (name == "Szansa (niebieska)")
        return blueCards_;
    else if (name == "Sieć wodociągów")
        return waterSupplyNetwork_;
    return nullptr;
}
