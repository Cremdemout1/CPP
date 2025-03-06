/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:51 by yohan             #+#    #+#             */
/*   Updated: 2025/02/26 17:25:34 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    try
    {
        Array<int> a(7);
        Array<std::string> b(132);

        for (int i = 0; i < 7; i++)
        {
            a[i] = i;
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Now giving value to index 131: " <<std::endl;
        b[131] = "hey im in bounds";
        std::cout << b[131] << std::endl;
        std::cout << "Now giving value to index 132: " <<std::endl;
        b[132] = "im not in bounds";
        std::cout << b[132] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}