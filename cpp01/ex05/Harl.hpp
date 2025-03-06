/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:40:44 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 14:00:54 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>

# define RED "\x1b[31;1m"
# define GREEN "\x1b[32;1m"
# define BLUE "\x1b[34;1m"
# define CYAN "\x1b[36;1m"
# define YELLOW "\033[33;1m"
# define RESET "\x1b[0m"

class Harl
{
    private:
    void    debug();
    void    info();
    void    warning();
    void    error();
    public:
    Harl();
    void    complain(std::string level);
    ~Harl();
};

#endif