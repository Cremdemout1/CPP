/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:02:17 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 17:06:09 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>

void to_lower(std::string &string)
{
    for (unsigned long i = 0; i < string.length(); i++)
        string[i] = std::tolower(string[i]);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

std::string Intern::validNames[3] = 
{
    "presidential pardon",
    "robotomy request",
    "shrubbery creation"
};

AForm *(*Intern::FormAddresses[3])(const std::string &target) = 
{
    &createPresidentialPardonForm,
    &createRobotomyRequestForm,
    &createShrubberyCreationForm
};

Intern::Intern()
{
    std::cout << "default Intern created\n";
}
Intern::Intern(const Intern &copy)
{
    *this = copy;
    std::cout << "copy of Intern created\n";
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
        *this = other;
    std::cout << "Intern copy operator called\n";
    return (*this);
}

AForm *Intern::makeForm(std::string &formName, std::string &target)
{
    to_lower(formName);
    for (int i = 0; i < 3; i++)
    {
        if (formName == validNames[i])
        {
            std::cout << "Intern has created " << formName << " for target " << target << std::endl;
            return(FormAddresses[i](target));
        }
    }
    throw (FormNotFoundException());
}

Intern::~Intern()
{
    std::cout << "Intern was destroyed\n";
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form Not found\n");
}