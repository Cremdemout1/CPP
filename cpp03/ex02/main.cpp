/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:12:49 by yohan             #+#    #+#             */
/*   Updated: 2025/02/10 08:45:19 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap robot1("R2D2");
    ScavTrap robot2("C3PO");
    FragTrap robot3("BB8");

    robot1.attack(robot2.getName());
    robot2.beRepaired(robot1.getAttackDamage());

    robot2.attack(robot1.getName());
    robot1.beRepaired(robot2.getAttackDamage());

    std::cout << robot2.getName() << " is doing well!\n";
    std::cout << "But they could use some backup...\n";

    robot3.highFivesGuys();

    // You can still perform actions like attack, repair with ClapTrap or ScavTrap
    robot3.attack(robot1.getName());
    robot1.beRepaired(robot3.getAttackDamage());

    robot3.attack(robot2.getName());
    robot2.beRepaired(robot3.getAttackDamage());

    // Output robot states
    std::cout << "The battle continues...\n";

    return 0;
}
