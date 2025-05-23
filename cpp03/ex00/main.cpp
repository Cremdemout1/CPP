/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:12:49 by yohan             #+#    #+#             */
/*   Updated: 2025/02/08 11:22:29 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap robot1("R2D2");
    ClapTrap robot2("C3PO");
    ClapTrap robot3;

    robot1.attack(robot2.getName());
    robot2.beRepaired(robot1.getAttackDamage());

    robot2.attack(robot1.getName());
    robot1.beRepaired(robot2.getAttackDamage());

    std::cout << robot3.getName() << " is a Spectator.\n";
    std::cout << "And this went on forever because they're smart\n";
}