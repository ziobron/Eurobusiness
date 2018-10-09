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
    Property(const std::string & name);
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

class Railway : public Property
{
    std::shared_ptr<State> stateRailway_;
public:
    Railway(const std::string & name);
    void setState(std::shared_ptr<State> state);
    int getPriceStamp(int rolls) const override;
};
