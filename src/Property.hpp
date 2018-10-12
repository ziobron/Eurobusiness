#pragma once

#include <string>
#include <vector>

class Property
{
    std::string name_;
    int purchasePrice_;
public:
    Property() = delete;
    Property(const Property &) = default;
    Property(Property &&) = delete;
    ~Property() = default;
    Property & operator=(const Property &) = delete;
    Property & operator=(Property &&) = delete;
    explicit Property(const std::string & name);

    int getPurchasePrice() const;
    std::string getName() const;
};

using Properties = std::vector<Property>;