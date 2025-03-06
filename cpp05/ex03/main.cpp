/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:49:27 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 17:05:09 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/Intern.hpp"

int main(void)
{
    std::string form = "shrubbery creation";
    try
    {
        Intern jake;
        Bureaucrat John;
        AForm   *scf;
        
        std::string name = John.getName();
        scf = jake.makeForm(form, name);
        scf->beSigned(John);
        scf->execute(John);
        
        form = "presidentgrervial pardon";
        scf = jake.makeForm(form, name);
        scf->beSigned(John);
        scf->execute(John);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}