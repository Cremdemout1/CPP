/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:02:19 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 16:53:50 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H
#include "AForm.hpp"

class Intern
{
    
    private:
    static std::string validNames[3];
    static AForm *(*FormAddresses[3])(const std::string &target); // array of pointers to functions
    public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &other);
    AForm *makeForm(std::string &formName, std::string &target);
    static AForm* createPresidentialPardonForm(const std::string &target);
    static AForm* createRobotomyRequestForm(const std::string &target);
    static AForm* createShrubberyCreationForm(const std::string &target);
    class FormNotFoundException : public std::exception
    {
        public:
        const char *what() const throw();
    };
    ~Intern();
};

#endif
