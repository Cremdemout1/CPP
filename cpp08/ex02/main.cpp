/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 07:56:00 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 08:24:00 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<std::string> stack;
    
    stack.push("hello");
    stack.push("again");
    stack.push("ramadan");
    MutantStack<std::string>::iterator it = stack.begin();
    stack.pop();
    while (it != stack.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
}