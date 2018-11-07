#pragma once

class State
{
public:
    virtual ~State() = default;
    virtual int getPriceStamp() = 0;
};

class YouCanBuy : public State
{
public:
    int getPriceStamp() { return 12;}
};
