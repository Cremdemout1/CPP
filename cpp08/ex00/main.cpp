/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:48:34 by yohan             #+#    #+#             */
/*   Updated: 2025/02/28 10:59:59 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    try
    {
        int array[10] = {1, 2, 3, 4, 5, 7, 4, 2, 0, 1111};
        std::vector<int> vector(array, array + sizeof(array) / sizeof(int));
        std::cout << ::easyfind(vector, 2) << std::endl;
        std::cout << ::easyfind(vector, 7) << std::endl;
        std::cout << ::easyfind(vector, 1111) << std::endl;
        std::cout << ::easyfind(vector, 22) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
        return (1);
    }
    return (0);
}