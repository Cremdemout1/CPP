/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:35:49 by yohan             #+#    #+#             */
/*   Updated: 2025/03/08 11:26:12 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ctime>
#include <iostream>

class Chronometer
{
    private:
            clock_t start_time;
            bool    running;
    public:
            Chronometer() : start_time(0), running(false){};
            void    start()
            {
                if (!running)
                {
                    start_time = clock();
                    running = true;
                }
            }
            double elapsed() // ends chronometer too
            {
                double elapsation = 0.0;
                if (running)
                    elapsation = (double)(clock() - start_time) / CLOCKS_PER_SEC;
                running = false;
                return elapsation;
            }
};