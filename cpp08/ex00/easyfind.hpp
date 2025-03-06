/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:11:55 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 07:55:33 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

template <typename T>
int    easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == std::end(container))
    {
        std::string error = "Number " + std::to_string(value) + " not found\n";
        throw(std::runtime_error(error));
    }
    return (*it);
}