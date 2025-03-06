/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:48:38 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 15:55:17 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

bool    fiftypercent()
{
    std::srand(std::time(0));
    return(rand() % 2 == 0);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72), target("default target")
{
    std::cout << "default Robotomy request called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 45, 72), target(target)
{
    std::cout << "Robotomy request with target: " << target << " called\n";
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 45, 72)
{
   *this = copy;
   std::cout << "Robotomy request copy constructor with target: " << target << " called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "Robotomy request copy operator with target: " << target << " called\n";
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy request destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    bool survivalRate = fiftypercent();
    std::cout << "BZZZzzzzTtttzT Bzzzitzzt\n";
    
    std::cout << bureaucrat.getName() << (survivalRate ? " It is with great joy that I inform you that " : " I'm sorry to inform you that ") << target 
        << (survivalRate ? " has been robotomized successfully" : " was not robotomized successfully... It failed") << std::endl;
}
