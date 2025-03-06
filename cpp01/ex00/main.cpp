/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:05:51 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 15:13:45 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    example(Zombie &zombie)
{
    zombie.announce();
    delete(&zombie);
}

int main(void)
{
    randomChump("Stack Memory (random chump)");
    Zombie *exampleZombie = newZombie("Heap memory");
    example(*exampleZombie);
    Zombie zombie("Stack memory");
    zombie.announce();
}