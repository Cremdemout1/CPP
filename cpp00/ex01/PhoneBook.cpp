/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:51:14 by yohan             #+#    #+#             */
/*   Updated: 2025/02/01 14:46:21 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook pb;
    std::string prompt;
    
    while (pb.getExitStatus() == 0)
    {
        std::cin >> prompt;
        if (prompt.compare("ADD") == 0)
            pb.Add();
        else if (prompt.compare("SEARCH") == 0)
            pb.Search();
        else if (prompt.compare("EXIT") == 0)
            pb.Exit();
    }
    return (0);
}