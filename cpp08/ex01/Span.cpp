/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:25:44 by yohan             #+#    #+#             */
/*   Updated: 2025/02/28 12:35:35 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int Num) : N(Num) 
{
    if (N <= 0 || N > 4294967295)
        throw(std::out_of_range("Maximum size of vector non admissible"));
}

Span::Span(const Span &copy)
{
    *this = copy;
}


Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->numbers = other.numbers;
    }
    return(*this);
}

Span::~Span() {}
        
void    Span::addNumber(int New)
{
    if (numbers.size() >= N)
        throw(std::runtime_error("Container is already full"));
    numbers.push_back(New);
}

int    Span::shortestSpan()
{
    int shortestSpan = std::numeric_limits<int>::max();
    int temp;
    
    if (numbers.size() <= 1)
        throw std::runtime_error("vector 'numbers' is too small");
    std::sort(numbers.begin(), numbers.end());
    for (std::vector<int>::iterator i = numbers.begin() + 1; i != numbers.end(); i++)
    {
        temp = *i - *(i - 1);
        if (temp < shortestSpan)
            shortestSpan = temp;
    }
    return (shortestSpan);
}

int    Span::longestSpan()
{
    if (numbers.size() <= 1)
        throw std::runtime_error("vector 'numbers' is too small");
    std::sort(numbers.begin(), numbers.end());
    return (numbers.back() - numbers.front());
}

std::vector<int> Span::getNumbers()
{
    return (numbers);
}