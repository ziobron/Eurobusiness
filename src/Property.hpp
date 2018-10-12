#pragma once

#include <string>
#include <vector>
#include <memory>

class Property
{
    std::string name_;
    int purchasePrice_;
public:
    Property() = delete;
    Property(const Property &) = delete;
    Property(Property &&) = delete;
    ~Property() = default;
    Property & operator=(const Property &) = delete;
    Property & operator=(Property &&) = delete;
    explicit Property(const std::string & name);

    int getPurchasePrice() const;
    std::string getName() const;
};

using PropertiesPtr = std::vector<std::shared_ptr<Property>>;
