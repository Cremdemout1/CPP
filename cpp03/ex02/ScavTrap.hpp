/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:26:16 by yohan             #+#    #+#             */
/*   Updated: 2025/02/10 08:26:56 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap	&operator=(const ScavTrap &other);
    ScavTrap(const ScavTrap &copy); // to copy values from existing object to new object
    void attack(const std::string& target);
    ~ScavTrap();
    void guardGate();
};

#endif