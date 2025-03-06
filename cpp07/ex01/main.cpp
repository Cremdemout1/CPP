/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:28 by yohan             #+#    #+#             */
/*   Updated: 2025/02/25 15:20:03 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(void)
{
    const char array[] = {'a', 'b', 'c', 'z', 'e'};
    ::iter(array, 5, ::printValue);
    ::iter(array, 5, ::convertToInt);
    
    const char* array1[] = {"hello", "world"};
    ::iter(array1, 2, ::printValue);
    
    std::string array2[] = {"hello", "how", "are", "you"};
    ::iter(array2, sizeof(array2) / sizeof (array2[0]), ::printValue);
}