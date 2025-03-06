/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:07:29 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 20:31:20 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
    std::string name;
    Weapon &weapon;
    public:
    HumanA(std::string name, Weapon &StartingWeapon);
    void    attack();
    ~HumanA();
};

#endif