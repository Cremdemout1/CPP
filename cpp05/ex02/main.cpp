/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:49:27 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 15:34:10 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"

int main(void)
{
    Bureaucrat e = Bureaucrat("Steven", 1);
    Bureaucrat j = Bureaucrat("Robby", 92);
    Bureaucrat topdawg = Bureaucrat("topDawg", 3);
    ShrubberyCreationForm shrub("Prime-Minister");
    RobotomyRequestForm robotomy("Geralt of Rivia");
    PresidentialPardonForm pres("trudeau");
    
    e.signForm(shrub);
    e.executeForm(shrub);
    j.signForm(robotomy);
    j.setgrade(42);
    j.signForm(robotomy);
    j.executeForm(robotomy);
    topdawg.signForm(pres);
    topdawg.executeForm(pres);
}