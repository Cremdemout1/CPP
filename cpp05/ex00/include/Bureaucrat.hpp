/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:32:41 by yohan             #+#    #+#             */
/*   Updated: 2025/02/16 08:36:40 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include <exception>
class Bureaucrat
{
    private:
    const std::string Name;
    int   Grade;
    public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string getName() const;
    void        setgrade(int grade);
    int         getGrade() const;
    
    void        incrementGrade();
    void        decrementGrade();
    
    class GradeTooHighException : public std::exception
    {
        public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif