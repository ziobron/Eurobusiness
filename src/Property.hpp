#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Field.hpp"
#include "Player.hpp"
#include "State.hpp"

using StatePtr = std::shared_ptr<State>;
using PlayerPtr = std::shared_ptr<Player>;
class Property : public Field
{
    int purchasePrice_;
    std::shared_ptr<Player> owner_;
protected:
    StatePtr state_;
public:
    Property() = delete;
    Property(const Property &) = delete;
    Property(Property &&) = delete;
    ~Property() = default;
    Property & operator=(const Property &) = delete;
    Property & operator=(Property &&) = delete;
    Property(const std::string & name, int price = 700);

    int getPurchasePrice() const;
    void doOn(PlayerPtr player);
    PlayerPtr getOwner() const;
    void setOwner(PlayerPtr player);
    int getPriceStamp() const;
    void setState(StatePtr state);
    bool doYouWantBuyThisProperty();
    PlayerPtr whoWantBuyThisProperty();
};

using PropertiesPtr = std::vector<std::shared_ptr<Property>>;
