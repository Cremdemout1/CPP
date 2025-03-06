/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:47:23 by yohan             #+#    #+#             */
/*   Updated: 2025/02/09 10:43:25 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), hitPoints(10), energyPoints(10), attackDamage(1)
{
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(1)
{
        std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) // to copy values from existing object to new object
{
    *this = copy;
    std::cout << "Copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) // to copy values of existing object to other existing object
{
    this->attackDamage = other.attackDamage;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->Name = other.Name;
    std::cout << "Copy assignment operator called\n";
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        if (energyPoints == 0)
            std::cout << "ClapTrap " << Name << " is incapacitated because it has 0 energyPoints\n";
        else if (hitPoints == 0)
            std::cout << "ClapTrap " << Name << " is incapacitated because it has 0 HP\n";
        return ;
    }
    energyPoints--;
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > 0 && (int)amount <= std::numeric_limits<int>::max())
        hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << Name << "is hit, causing " << amount << " points of damage! He is left with " << hitPoints << " HP\n";
    if (hitPoints == 0)
        std::cout << "ClapTrap " << Name << " has fainted...\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints != 0 || energyPoints != 0)
    {
        if (amount > 0 && (int)amount <= std::numeric_limits<int>::max())
            hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << Name << ", heals " << amount << " HP\n";
    }
}
    
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " has been destroyed\n";
}
    
std::string ClapTrap::getName()
{
    return (Name);
}
int ClapTrap::getHitPoints()
{
    return (hitPoints);
}
int ClapTrap::getAttackDamage()
{
    return (attackDamage);
}
int ClapTrap::getEnergyPoints()
{
    return (energyPoints);
}