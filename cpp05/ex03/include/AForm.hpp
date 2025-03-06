/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:40:39 by yohan             #+#    #+#             */
/*   Updated: 2025/02/18 16:43:25 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
    const std::string Name;
    bool              Signed;
    const int         executionGrade;
    const int         signatureGrade;
    public:
    
    AForm();
    AForm(std::string Name, const int execGrade, const int signGrade);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    
    int getSignGrade() const;
    int getExecGrade() const;
    bool      getSignedStatus() const;
    const     std::string getName() const;
    void      beSigned(const Bureaucrat &bureaucrat);

    virtual   void execute(Bureaucrat const & executor) const = 0;

    
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

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif