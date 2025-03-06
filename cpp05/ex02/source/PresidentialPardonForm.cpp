/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:03:45 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 15:55:24 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 5, 25), target("default target")
{
    std::cout << "default presidential pardon called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), target(target)
{
    std::cout << "presidential pardon with target: " << target << " called\n";
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 5, 25)
{
   *this = copy;
   std::cout << "presidential pardon copy constructor with target: " << target << " called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    std::cout << "presidential pardon copy operator with target: " << target << " called\n";
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "presidential pardon destructor called\n";
}
void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
    std::cout << "It is with much joy that we share with " << bureaucrat.getName() << " that " << target << " has been pardoned by noneother than Zaphod Beeblebrox!\n";
}
