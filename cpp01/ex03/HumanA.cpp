
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA()
{
    std::cout << "HumanA has been eliminated\n";
}

void    HumanA::attack()
{
        std::cout << name + " attacks with their " + weapon.getType() << std::endl;
}
