/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:19:29 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 20:42:27 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {weapon = nullptr;}

HumanB::~HumanB() {std::cout << name << " was destroyed\n";};

void    HumanB::attack()
{
    if (!weapon)
    {
        std::cout << name << " does not have a weapon!\n";
        return ;
    }
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &type)
{
    weapon = &type;
}

