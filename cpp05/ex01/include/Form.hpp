/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:40:39 by yohan             #+#    #+#             */
/*   Updated: 2025/02/18 16:38:19 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H
#include <iostream>

class Bureaucrat;

class Form
{
    private:
    const std::string Name;
    bool              Signed;
    const int         executionGrade;
    const int         signatureGrade;
    public:
    
    Form();
    Form(std::string Name, const int execGrade, const int signGrade);
    Form(const Form &copy);
    Form &operator=(const Form &other);
    ~Form();
    
    int getSignGrade() const;
    int getExecGrade() const;
    bool      getSignedStatus() const;
    const     std::string getName() const;
    void      beSigned(const Bureaucrat &bureaucrat);
    
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

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif