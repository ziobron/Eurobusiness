#pragma once

class State
{
public:
    virtual ~State() = default;
    virtual int getPriceStamp() = 0;
};
