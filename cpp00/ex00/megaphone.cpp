/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:03:57 by yohan             #+#    #+#             */
/*   Updated: 2025/01/31 09:37:12 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    megaphonify(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
    std::cout << str;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
            megaphonify(argv[i]);
    }
    std::cout << std::endl;
    return (0);
}