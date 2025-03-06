/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:59:48 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 20:34:34 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

class Weapon
{
    private:
    std::string type;
    public:
    Weapon(std::string Type);
    const std::string   &getType();
    void                setType(std::string newType);
    ~Weapon();
};

#endif