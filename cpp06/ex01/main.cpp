/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:22:09 by yohan             #+#    #+#             */
/*   Updated: 2025/02/22 14:35:41 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"

int main(void)
{
    Data product;
    product.brandName = "Coca-Cola";
    product.product = "fizzy drink";
    product.cost = 3.99;
    
    std::cout << "Before: " << std::endl;
    
    std::cout << product.brandName << std::endl;
    std::cout << product.product << std::endl;
    std::cout << product.cost << std::endl;

    uintptr_t raw = Serializer::serialize(&product);
    Data *deserialized = Serializer::deserialize(raw);

    std::cout << std::endl << "After Serialization: " << std::endl;
    
    std::cout << deserialized->brandName << std::endl;
    std::cout << deserialized->product << std::endl;
    std::cout << deserialized->cost << std::endl;
}