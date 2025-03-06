/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:22:51 by yohan             #+#    #+#             */
/*   Updated: 2025/02/16 08:37:16 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat e = Bureaucrat("Steven", 4);
        std::cout << e << std::endl;
        e.setgrade(82);
        std::cout << e << std::endl;
        e.setgrade(1);
        e.incrementGrade();
        std::cout << e << std::endl;
        e.setgrade(150);
        e.decrementGrade();
        std::cout << e << std::endl;
        e.setgrade(149);
        e.decrementGrade();
        std::cout << e << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Bureaucrat experiement halted\n";
    }
    return (0);
}