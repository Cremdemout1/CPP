/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:07:29 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 20:37:59 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
    std::string name;
    Weapon *weapon; // a pointer to a referrence because a pointer can point to null
    public:
    HumanB(std::string name);
    void    attack();
    void    setWeapon(Weapon &type);
    ~HumanB();
};

#endif