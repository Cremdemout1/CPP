#include "Zombie.hpp"

Zombie::Zombie(const std::string n) : name(n) {}

void    Zombie::announce(void)
{
    std::cout << Zombie::name + ": BraiiiiiiinnnzzzZ...\n";
}
