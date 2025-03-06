/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:55:43 by yohan             #+#    #+#             */
/*   Updated: 2025/02/18 16:40:27 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : Name("Default"), Signed(false), executionGrade(1), signatureGrade(1)
{
    std::cout << "Default form constructor called\n";
}

Form::Form(std::string Name, const int execGrade, const int signGrade) : Name(Name), Signed(false), executionGrade(execGrade), signatureGrade(signGrade)
{
    std::cout << Name << " constructor called\n";
}

Form::Form(const Form &copy) : Name(copy.Name), Signed(copy.Signed), executionGrade(copy.executionGrade), signatureGrade(copy.signatureGrade)
{
    std::cout << "Form copy constructor called\n";
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->Signed = other.Signed;
    std::cout << "Form copy operator called\n";
    return (*this);
}

Form::~Form()
{
    std::cout << Name << " destroyed\n";
}

int Form::getSignGrade() const
{
    return(signatureGrade);
}

int Form::getExecGrade() const
{
    return (executionGrade);
}

bool      Form::getSignedStatus() const
{
    return(Signed);
}

const std::string Form::getName() const
{
    return (Name);
}

void      Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signatureGrade)
        throw GradeTooHighException();
    Signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade of Form is too high\n");
}
const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade of Form is too low\n");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    std::string status;
    status = f.getSignedStatus() == true ? "yes" : "no";
    out << "Form " << f.getName() << "\nSigned: " << status << "\nSignature Rank: " << f.getSignGrade() << "\nExecution Rank: " << f.getExecGrade() << std::endl;
    return (out);
}
