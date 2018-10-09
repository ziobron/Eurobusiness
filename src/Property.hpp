#pragma once
#include <string>
#include <memory>

class State;

class Property
{
    std::string name_;
    int purchasePrice_;
public:
    virtual ~Property() = default;
    Property(const std::string & name, int purchasePrice);
    int getPurchasePrice() const;
    std::string getName() const;
    virtual void setState(std::shared_ptr<State>) = 0;
    virtual int getPriceStamp(int rolls = 0) const = 0;
};

class State
{
public:
    virtual ~State() = default;
    virtual int getPriceStamp() const {}
};

class StateRailway : public State
{
public:
    virtual int getPriceStamp() const {}
};

class OneRailway : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class TwoRailwais : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class ThreeRailwais : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class FourRailwais : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class StateCity : public State
{
public:
    virtual int getPriceStamp() const {}
};

class NoBuilding : public StateCity
{
public:
    int getPriceStamp() const override;
};

class OneHouse : public StateCity
{
public:
    int getPriceStamp() const override;
};

class TwoHouses : public StateCity
{
public:
    int getPriceStamp() const override;
};

class ThreeHouses : public StateCity
{
public:
    int getPriceStamp() const override;
};

class FourHouses : public StateCity
{
public:
    int getPriceStamp() const override;
};

class OneHotel : public StateCity
{
public:
    int getPriceStamp() const override;
};

class Railwais : public Property
{
    std::shared_ptr<State> stateRailway_;
public:
    Railwais(const std::string & name, int purchasePrice);
    void setState(std::shared_ptr<State> state);
    int getPriceStamp(int rolls) const override;
};

class Railway : public Railwais
{
public:
    Railway(const std::string & name, int purchasePrice = 120);
};

class City : public Property
{
    std::shared_ptr<State> stateCity_;
public:
    City(const std::string & name, int purchasePrice = 700);
    int getPriceStamp(int rolls) const override;
    void setState(std::shared_ptr<State> state);
};
