/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:03:21 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 20:43:37 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string Type) {type = Type;};

Weapon::~Weapon() {std::cout << type << " was destroyed\n";};

const std::string &Weapon::getType()
{
    return(type);
}

void    Weapon::setType(std::string newType)
{
    type = newType;
}