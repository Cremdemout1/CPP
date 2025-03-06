/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:14:07 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 20:42:21 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    Weapon secondclub = Weapon("crude spiked club");
    HumanB jim("Jim");
    //jim.setWeapon(secondclub);
    jim.attack();
    club.setType("some other type of club");
    jim.setWeapon(club);
    jim.attack();
    return 0;
}