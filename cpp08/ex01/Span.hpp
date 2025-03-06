/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:01:51 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 07:55:27 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>

class Span
{
    private:
        unsigned int        N;
        std::vector <int>   numbers;
    public:
        Span(unsigned int Num);
        Span(const Span &copy);
        Span &operator=(const Span &other);
        ~Span();
        
        void    addNumber(int New);
        int     shortestSpan();
        int     longestSpan();
        std::vector<int> getNumbers();
};