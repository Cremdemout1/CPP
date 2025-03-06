/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:47 by yohan             #+#    #+#             */
/*   Updated: 2025/02/25 15:11:16 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename value>
void    printValue(value &values)
{
    std::cout << values << std::endl;
}

template <typename value>
void    convertToInt(value &values)
{
    std::cout << static_cast<int>(values) << std::endl;
}

template <typename value>
void    iter(const value  array[], size_t len, void (*func)(const value &))
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

#endif