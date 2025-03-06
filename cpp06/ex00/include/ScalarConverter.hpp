/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:59:01 by yohan             #+#    #+#             */
/*   Updated: 2025/02/21 12:19:24 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
#include <iostream>

class ScalarConverter
{
    private:
            ScalarConverter();
            ScalarConverter(const ScalarConverter &copy);
            ScalarConverter &operator=(const ScalarConverter &other);
            ~ScalarConverter();
    public:
            static void convert(const std::string &literal);   
};

#endif