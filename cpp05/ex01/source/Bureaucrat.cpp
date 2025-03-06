/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:38:43 by yohan             #+#    #+#             */
/*   Updated: 2025/02/18 16:25:44 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat() : Name("Default"), Grade(1)
{
    std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :Name(name), Grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << Name << " constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : Name(copy.Name)
{
    *this = copy;
    std::cout << "Copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        if (other.Grade < 1)
            throw GradeTooHighException();
        else if (other.Grade > 150)
            throw GradeTooLowException();
        this->Grade = other.Grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << Name << " destroyed\n";
}

std::string Bureaucrat::getName() const
{
    return (Name);
}
void        Bureaucrat::setgrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    Grade = grade;
}
int         Bureaucrat::getGrade() const
{
    return(Grade);
}

void        Bureaucrat::incrementGrade()
{
    if (Grade - 1 < 1)
        throw GradeTooHighException();
    Grade -= 1;
}
void        Bureaucrat::decrementGrade()
{
    if (Grade + 1 > 150)
        throw GradeTooLowException();
     Grade += 1;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too Low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High!");
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade "
		<< b.getGrade() << "." << std::endl;
	return (out);
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << Name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::string reason = e.what();
        std::cout << Name << " couldn't sign " << form.getName() << " because " << reason << std::endl;
    }
    
}