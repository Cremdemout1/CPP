/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 08:41:51 by yohan             #+#    #+#             */
/*   Updated: 2025/02/09 10:29:59 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
    protected:
    std::string Name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
    
    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &copy);// to copy values from existing object to new object
    ClapTrap &operator=(const ClapTrap &other);  // to copy values of existing object to other existing object
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName();
    int getHitPoints();
    int getAttackDamage();
    int getEnergyPoints();
    ~ClapTrap();
};

#endif