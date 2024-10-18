
#include "Zombie.hpp"

int main()
{
    std::string name;
    std::cout << "choose zombie name";
    std::cin >> name;
    
    Zombie *allocated = zombieHorde(15, name + "(heap)");
    for (int i = 0; i < 15; i++)
        allocated[i].announce();
    delete[](allocated);
    return (0);
}