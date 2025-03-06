/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:26:46 by yohan             #+#    #+#             */
/*   Updated: 2025/02/10 08:33:22 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    energyPoints = 50;
    hitPoints = 100;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    energyPoints = 50;
    hitPoints = 100;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        if (energyPoints == 0)
            std::cout << "ScavTrap " << Name << " is incapacitated because it has 0 energyPoints\n";
        else if (hitPoints == 0)
            std::cout << "ScavTrap " << Name << " is incapacitated because it has 0 HP\n";
        return ;
    }
    energyPoints--;
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " has been destroyed\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) // to copy values of existing object to other existing object
{
    this->attackDamage = other.attackDamage;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->Name = other.Name;
    std::cout << "ScavTrap Copy assignment operator called\n";
    return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) // Copy Contructor
{
	*this = copy;

	std::cout << "ScavTrap Copy contructor called" << std::endl;
}