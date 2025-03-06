/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:43:17 by yohan             #+#    #+#             */
/*   Updated: 2025/02/05 13:55:35 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void Search();
#include "PhoneBook.h"

int    PhoneBook::getExitStatus()
{
    return exitStatus;
}

void    PhoneBook::setExitStatus(int value)
{
    exitStatus = value;
}

int    PhoneBook::getIndex()
{
    return index;
}

void    PhoneBook::setIndex(int value)
{
    index = value;
}

void    PhoneBook::setStuckIndex(bool value)
{
    stuckIndex = value;
}

void    PhoneBook::Add()
{
    std::cout << index << std::endl;
    if (index < 8)
    {
        contacts[index].AddContact();
        index++;
    }
    else
    {
        index = 0;
        contacts[index].AddContact();
        index++;
        stuckIndex = true;
    }
}

std::string    wordFitting(std::string fullWord)
{
    std::string space = "          ";
    std::string fittedName = fullWord.substr(0, 10);
    if (fullWord.length() > 10)
        fittedName[9] = '.';
    int len = fittedName.length();
    for (int i = 0; i < len; i++)
        space[10 - len + i] = fittedName[i];
    return (space);
}

void    PhoneBook::Search()
{
    int idx = index;
    if (stuckIndex == true)
        idx = 8;
    std::cout << " ___________________________________________ \n";
    for (int i = 0; i < idx; i++)
    {
        std::cout << "|";
        std::string strIndex = "          ";
        strIndex[9] = '0' + static_cast<char>(i);
        std::cout << strIndex + "|";
        std::cout << wordFitting(contacts[i].getFirstName()) + "|";
        std::cout << wordFitting(contacts[i].getLastName()) + "|";
        std::cout << wordFitting(contacts[i].getNickName()) + "|\n";
    }
    std::cout << " ___________________________________________ \n";
    // prompt for index:
    std::string prompt;
    std::cout << "Enter index: ";
    std::cin >> prompt;
    while (prompt.length() > 1 || prompt[0] < '0' || prompt[0] > idx - 1 + '0')
    {
        std::cout <<"Invalid index. Please choose between 0 and " << idx - 1 << std::endl;
        std::cout << "Enter index:";
        std::cin >> prompt;
    }
    int chosenIndex = atoi(prompt.c_str());
    std::cout << "First Name: " << contacts[chosenIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[chosenIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[chosenIndex].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[chosenIndex].getPhoneNum() << std::endl;
    std::cout << "Deepest Darket Secret: " << contacts[chosenIndex].getSecret() << std::endl;
}

void    PhoneBook::Exit()
{
    std::cout << "Goodbye!\n";
    setExitStatus(1);
}

PhoneBook::PhoneBook()
{
    setExitStatus(0);
    setIndex(0);
    setStuckIndex(false);
    std::cout << "PhoneBook created\n";
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destroyed\n";
}