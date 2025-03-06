/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:49:27 by yohan             #+#    #+#             */
/*   Updated: 2025/02/18 16:29:22 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"

int main(void)
{
    Bureaucrat e = Bureaucrat("Steven", 1);
    Bureaucrat copy = Bureaucrat(e);
    Form superImportantForm = Form("the most important form ever", 1, 1);
    Form otherWeirdForm = Form("unimportant form", 69, 15);

    copy.setgrade(90);
    
    e.signForm(superImportantForm);
    copy.signForm(superImportantForm);

    e.signForm(otherWeirdForm);
    copy.signForm(otherWeirdForm);
}