/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:53:37 by yohan             #+#    #+#             */
/*   Updated: 2025/02/10 08:44:26 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    energyPoints = 50;
    hitPoints = 100;
    attackDamage = 20;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    energyPoints = 50;
    hitPoints = 100;
    attackDamage = 20;
    std::cout << "FragTrap constructor called\n";
}
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap Copy assignment operator called\n";
    return (*this);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) // to copy values from existing object to new object
{
    *this = copy;

	std::cout << "FragTrap Copy contructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " has requested a high five!\n";
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " has been destroyed\n";
}
