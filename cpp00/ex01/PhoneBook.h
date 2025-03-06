/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:54:27 by yohan             #+#    #+#             */
/*   Updated: 2025/02/01 19:25:21 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
const int MaxContactNum = 8;

class Contact
{
    private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber; // must be string so that I can accept +
    std::string Secret;
    public:
    Contact();
    void AddContact();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNum();
    std::string getSecret();
    bool ValidPhoneNumber(std::string &num);
    ~Contact();
};

class PhoneBook
{
    private:
    bool    exitStatus;
    int     index;
    int     stuckIndex;
    Contact contacts[MaxContactNum];
    
    public:
    PhoneBook();
    
    int getIndex();
    void setIndex(int value);
    void setStuckIndex(bool value);
    int getExitStatus();
    void setExitStatus(int value);
    
    void Add();
    void Search();
    void Exit();
    ~PhoneBook();
};

#endif