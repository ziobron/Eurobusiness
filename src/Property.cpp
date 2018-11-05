#include "Property.hpp"
#include <iostream>

Property::Property(const std::string & name, int price) :
    Field(name),
    purchasePrice_(price),
    owner_(nullptr),
    state_(std::make_shared<YouCanBuy>())
{}

int Property::getPurchasePrice() const
{
    return purchasePrice_;
}

void Property::doOn(std::shared_ptr<Player> player)
{
    if (owner_ == nullptr)
    {
        if (doYouWantBuyThisProperty())
        {
            owner_ = player;
            player->reduceMoney(purchasePrice_);
        } else 
        {
            PlayerPtr newOwner = whoWantBuyThisProperty();
            newOwner->reduceMoney(purchasePrice_);
        }
    } else if (player != owner_) 
    {
        player->reduceMoney(getPriceStamp());
        owner_->addMoney(getPriceStamp());
    }
}

std::shared_ptr<Player> Property::getOwner() const
{
    return owner_;
}

void Property::setOwner(std::shared_ptr<Player> player)
{
    owner_ = player;
}

int Property::getPriceStamp() const
{
    return state_->getPriceStamp();
}

void Property::setState(StatePtr state)
{
    state_ = state;
}

bool Property::doYouWantBuyThisProperty()
{
    std::cout << "Do you want buy this property?" << std::endl;
    return 1;
}

PlayerPtr Property::whoWantBuyThisProperty()
{
    std::cout << "Action of property?" << std::endl;
    std::cout << "Odpytaj każdego gracza czy chce kupic nieruchomosc - playerPtr->doYouWantBuyThisProperty" << std::endl;
    //return 1;
}
