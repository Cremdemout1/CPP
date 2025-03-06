/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:26:17 by yohan             #+#    #+#             */
/*   Updated: 2025/02/25 12:26:46 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/Classes.hpp"

Base::~Base() {};

Base *generate(void)
{
    std::srand(std::time(0));
    int gen = std::rand() % 3;
    if (gen == 0)
        return (new(A));
    else if (gen == 1)
        return (new(B));
    else if (gen == 2)
        return (new(C));
    return (NULL);
}


void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unrecognized pointer\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    }
    catch(const std::exception& e) {}
}