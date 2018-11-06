#include "Board.hpp"
#include "City.hpp"
#include "Cards.hpp"
#include "Railway.hpp"
#include "OrdinaryCard.hpp"
#include <string>
#include <fstream>

Board::Board(const std::string & fileName) :
    fields_(40)
{
    json j = readFile(fileName);
    setCards(j);
    setFieldToCards(j);
}

FieldPtr Board::getField(const unsigned int numberOfField) const noexcept
{
    return fields_.at(numberOfField);
}

FieldPtr Board::factoryFields(const std::string & name)
{
    auto pos = name.find("-");
    if (pos != std::string::npos)
        return std::make_shared<City>(name.substr(pos + 2), "sd");
    else if (name.find("Koleje") != std::string::npos)
        return std::make_shared<Railway>(name);
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
        fields_.at(stoi(it.key())) = ffactoryFields(it.value());
}

FieldPtr Board::ffactoryFields(const std::string & name)
{
    if (name == "Szansa (czerwona)")
        return redCards_;
    else if (name == "Szansa (niebieska)")
        return blueCards_;
    else if (name == "Sieć wodociągów")
        return std::make_shared<WaterSupplyNetwork>(name, 120);
    return factoryFields(name);
}
