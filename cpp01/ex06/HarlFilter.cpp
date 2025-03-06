/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:30 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 14:31:09 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

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
    int numlvl;
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    if (level == "DEBUG")
        numlvl = 0;
    else if (level == "INFO")
        numlvl = 1;
    else if (level == "WARNING")
        numlvl = 2;
    else if (level == "ERROR")
        numlvl = 3;
    else
        numlvl = -1;
    if (numlvl == -1)
        std::cout << "[ Probably complaining about insignificant problems ]\n";
    switch(numlvl)
    {
        case 0:
            (this->*functions[0])();
        case 1:
            (this->*functions[1])();
        case 2:
            (this->*functions[2])();
        case 3:
            (this->*functions[3])();
            break ;
    }
}

Harl::~Harl(){};