#include "Weapon.hpp"

    Weapon::Weapon(std::string type) : type(type) {}

    Weapon::~Weapon()
    {
        std::cout << "weapon destroyed\n";
    }

    const std::string &Weapon::getType()
    {
        return (type);
    }

    void Weapon::setType(std::string newType)
    {
        type = newType;
    }