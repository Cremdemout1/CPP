/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:08:08 by yohan             #+#    #+#             */
/*   Updated: 2025/03/03 23:09:51 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>


class RPN
{
    private:
            std::stack<float> operation;
            long long         result;
            float             calculate(char operator);
            void              runRPN(const std::string &str, std::string &delimiter);
    public:
            RPN(std::string &input);
            RPN(const RPN &copy);
            RPN &operator=(const RPN &other);
            ~RPN();
}