/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:11:45 by yohan             #+#    #+#             */
/*   Updated: 2025/02/21 12:33:49 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc <= 1)
        return (1);
    for (int i = 1; i < argc; i++)
    {
        ScalarConverter::convert(std::string(argv[i]));
        if (i != argc - 1)
            std::cout << std::endl;
    }
    return(0);
}