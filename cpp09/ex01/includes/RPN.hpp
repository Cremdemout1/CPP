/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:08:08 by yohan             #+#    #+#             */
/*   Updated: 2025/03/06 22:47:38 by yohan            ###   ########.fr       */
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
            void             calculate(const char op);
            void             runRPN(const std::string &str);
            void             parseInput(const std::string &input);
    public:
            RPN(const std::string &input);
            RPN(const RPN &copy);
            RPN &operator=(const RPN &other);
            ~RPN();
};