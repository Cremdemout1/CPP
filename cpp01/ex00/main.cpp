
#include "Zombie.hpp"

int main()
{
    std::string name;
    std::cout << "choose zombie name";
    std::cin >> name;
    
    Zombie *allocated = newZombie(name + "(heap)");
    allocated->announce();
    randomChump(name + "(stack)");
    delete(allocated);
    return (0);
}