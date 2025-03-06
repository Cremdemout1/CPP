/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:02:51 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 13:55:25 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

bool Contact::ValidPhoneNumber(std::string &num)
{
    int i = 0;
    int count = 0;
    while (num[i] == '\t' || num[i] == ' ' || num[i] == '\n')
            i++;
    if (num[i] == '+')
        i++;
    while (num[i])
    {
        int spaceCount = 0;
        while (num[i] == ' ')
        {
            if (spaceCount > 0)
                return (false);
            spaceCount++;
            i++;
        }
        if (num[i] < '0' || num[i] > '9' || count > 15)
            return (false);
        i++;
        count++;
    }
    return (true);
}

std::string Contact::getFirstName()
{
    return(FirstName);
}

std::string Contact::getLastName()
{
    return(LastName);
}

std::string Contact::getNickName()
{
    return(NickName);
}

std::string Contact::getPhoneNum()
{
    return(PhoneNumber);
}

std::string Contact::getSecret()
{
    return(Secret);
}

void Contact::AddContact()
{
    std::string tempPhoneNumber;
    std::cout << "Enter Contact First Name: ";
    std::cin.ignore();
    std::getline(std::cin, FirstName);

    std::cout << "Enter Contact Last Name: ";
    std::getline(std::cin, LastName);
    
    std::cout << "Enter Contact Nickname: ";
    std::getline(std::cin, NickName);
    
    std::cout << "Enter Phone Number (e.g., +1 134 456 6789): ";
    std::getline(std::cin, tempPhoneNumber);
    while (!ValidPhoneNumber(tempPhoneNumber))
    {
        std::cout << "Invalid phone number. Please try again.\n";
        std::cout << "Enter Phone Number (e.g., +1 134 456 6789): ";
        std::getline(std::cin, tempPhoneNumber);
    }
    PhoneNumber = tempPhoneNumber;
    
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, Secret);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}
