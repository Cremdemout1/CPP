/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:55:43 by yohan             #+#    #+#             */
/*   Updated: 2025/02/20 15:52:06 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : Name("Default"), Signed(false), executionGrade(1), signatureGrade(1)
{
    std::cout << "Default Aform constructor called\n";
}

AForm::AForm(std::string Name, const int execGrade, const int signGrade) : Name(Name), Signed(false), executionGrade(execGrade), signatureGrade(signGrade)
{
    std::cout << Name << " constructor called\n";
}

AForm::AForm(const AForm &copy) : Name(copy.Name), Signed(copy.Signed), executionGrade(copy.executionGrade), signatureGrade(copy.signatureGrade)
{
    std::cout << "AForm copy constructor called\n";
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->Signed = other.Signed;
    std::cout << "AForm copy operator called\n";
    return (*this);
}

AForm::~AForm()
{
    std::cout << Name << " destroyed\n";
}

int AForm::getSignGrade() const
{
    return(signatureGrade);
}

int AForm::getExecGrade() const
{
    return (executionGrade);
}

bool      AForm::getSignedStatus() const
{
    return(Signed);
}

const std::string AForm::getName() const
{
    return (Name);
}

void      AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > signatureGrade)
        throw GradeTooHighException();
    Signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade of AForm is too high\n");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade of AForm is too low\n");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    std::string status;
    status = f.getSignedStatus() == true ? "yes" : "no";
    out << "AForm " << f.getName() << "\nSigned: " << status << "\nSignature Rank: " << f.getSignGrade() << "\nExecution Rank: " << f.getExecGrade() << std::endl;
    return (out);
}
