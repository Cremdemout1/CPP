/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:19:36 by yohan             #+#    #+#             */
/*   Updated: 2025/02/25 12:28:57 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Base.hpp"
#include "./include/Classes.hpp"

int main(void)
{
    A a;
    B b;
    C c;

    identify(&a);
    identify(&b);
    identify(&c);

    A *a1 = new A();
    B *b1 = new B();
    C *c1 = new C();
    
    identify(*a1);
    identify(*b1);
    identify(*c1);

    delete(a1);
    delete(b1);
    delete(c1);
}