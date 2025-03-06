/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:30 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 14:15:21 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

void    Harl::debug()
{
    std::cout << CYAN << "[ DEBUG MODE ]\n" << RESET;
}

void    Harl::info()
{
    std::cout << GREEN << "[ INFO MODE ]\n" <<  RESET;
}

void    Harl::warning()
{
    std::cout << YELLOW << "[ WARNING MODE ]\n" << RESET;
}

void    Harl::error()
{
    std::cout << RED << "[ ERROR MODE ]\n" << RESET;
}

void    Harl::complain(std::string level)
{
    // functions is an array of function pointers that take nothing as argument
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < int(sizeof(levels) / sizeof(levels[i])); i++)
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
    std::cout << "[ UNKNOWN ]\n";
}

Harl::~Harl(){};