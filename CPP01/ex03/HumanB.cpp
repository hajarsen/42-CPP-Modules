#include "HumanB.hpp"

HumanB::HumanB(std::string name) 
    : name(name)
    , weapon(NULL) 
{

}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;
}

void HumanB::attack() const 
{
    if (weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
