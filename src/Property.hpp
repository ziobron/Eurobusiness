#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Field.hpp"
#include "Player.hpp"

class Property : public Field
{
    std::string name_;
    int purchasePrice_;
    std::shared_ptr<Player> owner_;
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
    void doOn(std::shared_ptr<Player> player);
    std::shared_ptr<Player> getOwner() const;
    void setOwner(std::shared_ptr<Player> player);
};

using PropertiesPtr = std::vector<std::shared_ptr<Property>>;
