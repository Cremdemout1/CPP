/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:14:03 by yohan             #+#    #+#             */
/*   Updated: 2025/02/28 12:41:07 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    size_t N = 100000;
    std::srand(std::time(0));
    Span *vect = new Span(N);
    for (size_t i = 0; i < N; i++)
    {
        try
        {
            vect->addNumber(static_cast<int>(std::rand()));
        }
        catch(const std::exception& e)
        {
                std::cerr << e.what() << '\n';
            }
        }

        int spanLongest = vect->longestSpan();
        int spanShortest = vect->shortestSpan();
    
        std::cout << "Longest Span from Span class: " << spanLongest << std::endl;
        std::cout << "Shortest Span from Span class: " << spanShortest << std::endl;
    
        // Manually calculate the longest and shortest spans
        std::vector<int> numbersCopy = vect->getNumbers();
    
        std::sort(numbersCopy.begin(), numbersCopy.end());
        int manualLongest = numbersCopy.back() - numbersCopy.front();
        int manualShortest = std::numeric_limits<int>::max();
        for (size_t i = 1; i < numbersCopy.size(); ++i) {
            int temp = numbersCopy[i] - numbersCopy[i - 1];
            if (temp < manualShortest)
                manualShortest = temp;
        }
    
        std::cout << "Manual Longest Span: " << manualLongest << std::endl;
        std::cout << "Manual Shortest Span: " << manualShortest << std::endl;
    
        // Validate the results
        if (spanLongest == manualLongest)
            std::cout << "Longest span is correct!" << std::endl;
        else
            std::cout << "Longest span is incorrect!" << std::endl;
    
        if (spanShortest == manualShortest)
            std::cout << "Shortest span is correct!" << std::endl;
        else
            std::cout << "Shortest span is incorrect!" << std::endl;    
        delete(vect);
        vect = new Span(2);
        vect->addNumber(8);
        try
        {
            vect->addNumber(2);
            vect->addNumber(1);
            vect->addNumber(9);

            
            vect->longestSpan();
            vect->shortestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete(vect);
        return (0);
}