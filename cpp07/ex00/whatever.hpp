/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:22:33 by yohan             #+#    #+#             */
/*   Updated: 2025/02/25 14:41:48 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATERVER_HPP
#define WHATERVER_HPP
#include <iostream>

template <typename T>

void    swap(T &data1, T &data2)
{
    T temp = data1;
    data1 = data2;
    data2 = temp;
}

template <typename value>
const value   &min(const value &data1, const value &data2)
{
    return ((data1 < data2) ? data1 : data2);
}

template <typename value>
const value   &max(const value &data1, const value &data2)
{
    return ((data1 > data2) ? data1 : data2);
}

#endif