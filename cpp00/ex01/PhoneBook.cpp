/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:51:14 by yohan             #+#    #+#             */
/*   Updated: 2025/04/27 12:35:40 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook pb;
    std::string prompt;
    
    signal(SIGINT, handle_sigint);
    while (pb.getExitStatus() == 0)
    {
        
        std::cout << "Type a command (ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, prompt);
        if (std::cin.eof())
            break ;
        if (prompt.compare("ADD") == 0)
            pb.Add();
        else if (prompt.compare("SEARCH") == 0)
        {
            if (pb.getIndex() == 0)
            {
                std::cout << "No contacts have been added yet\n";
                continue ;
            }
            else
                pb.Search();
        }
        else if (prompt.compare("EXIT") == 0)
            pb.Exit();
    }
    return (0);
}