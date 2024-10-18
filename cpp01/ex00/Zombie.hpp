
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
    std::string name;

    public:
    Zombie(std::string n);
    void    announce(void);
    ~Zombie()
    {
        std::cout << "destroying " + name + " from Heap" << std::endl;
    }
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif