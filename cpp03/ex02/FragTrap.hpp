/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:50:06 by yohan             #+#    #+#             */
/*   Updated: 2025/02/10 08:42:05 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_H
#define FragTrap_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap &operator=(const FragTrap &other);
    FragTrap(const FragTrap &copy); // to copy values from existing object to new object
    void highFivesGuys(void);
    ~FragTrap();
};
#endif