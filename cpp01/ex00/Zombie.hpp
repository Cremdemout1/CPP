/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:34:19 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 15:05:28 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
    std::string name;
    
    public:
    Zombie(std::string name);
    void    announce();
    ~Zombie();
};

Zombie  *newZombie(std::string name);
void    randomChump( std::string name);

#endif
