/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:49:45 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 15:59:23 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

std::string art = "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n       / \\";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145), target("default target")
{
    std::cout << "default Shrubbery Creation called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145), target(target)
{
    std::cout << "Shrubbery Creation with target: " << target << " called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 137, 145)
{
   *this = copy;
   std::cout << "Shrubbery Creation copy constructor with target: " << target << " called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "Shrubbery Creation copy operator with target: " << target << " called\n";
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Creation destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
    std::cout << bureaucrat.getName() << " is executing the shrubbery creation request\n";
    std::string name = target + "_shrubbery";
    std::ofstream fd(name);
    if (fd.is_open())
        fd << art;
    fd.close();
}
