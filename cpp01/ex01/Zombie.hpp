/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:34:19 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 19:18:10 by yohan            ###   ########.fr       */
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
    Zombie();
    void    announce();
    void    setName(std::string name);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif
