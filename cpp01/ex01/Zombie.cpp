/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:41:32 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 19:20:57 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << name << " Destroyed\n";
}

void    Zombie::announce()
{
    std::cout << name <<": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string new_name)
{
    name = new_name;
}