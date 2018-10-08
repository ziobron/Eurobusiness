#include <iostream>
#include "Eurobusiness.hpp"
#include "Property.hpp"
#include <memory> 

int main()
{
    std::shared_ptr<Property> p = std::make_shared<Railway>("railway", 120);
    p->setState(std::make_shared<OneRailway>());
    std::cout << "Eurobusiness!" << std::endl;
    return 0;
}
