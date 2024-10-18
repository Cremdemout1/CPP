
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
    std::string name;

    public:
    Zombie();
    Zombie(std::string n);
    void    announce(void);
    ~Zombie()
    {
        std::cout << "destroying " + name + " from Heap" << std::endl;
    }
};

Zombie* zombieHorde(int N, std::string name);

#endif