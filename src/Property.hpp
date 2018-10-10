#pragma once
#include <string>

class Property
{
    std::string name_;
    int purchasePrice_;
public:
    Property(const std::string & name);
    int getPurchasePrice() const;
    std::string getName() const;
};
