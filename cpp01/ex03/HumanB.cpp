
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB()
{
    std::cout << "HumanB has been eliminated\n";
}

void    HumanB::attack()
{
    if (!weapon)
    {
        std::cout << name + "does not have a weapon...\n";
        return ;
    }
    std::cout << name + " attacks with their " + weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    HumanB::weapon = &weapon;
}