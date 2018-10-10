#pragma once
#include <string>

class Property
{
    std::string name_;
    int purchasePrice_;
public:
    Property() = delete;
    Property(const Property &) = default;
    Property(Property &&) = default;
    ~Property() = default;
    Property & operator=(const Property &) = default;
    Property & operator=(Property &&) = default;
    explicit Property(const std::string & name);

    int getPurchasePrice() const;
    std::string getName() const;
};
