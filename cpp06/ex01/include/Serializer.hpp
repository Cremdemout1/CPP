/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:17:12 by yohan             #+#    #+#             */
/*   Updated: 2025/02/22 14:32:17 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
            Serializer();
            Serializer(const Serializer &copy);
            Serializer &operator=(const Serializer &other);
            ~Serializer();
    public:
            static uintptr_t serialize(Data* ptr);
            static Data* deserialize(uintptr_t raw);
};

#endif