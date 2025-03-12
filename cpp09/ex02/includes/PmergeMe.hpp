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
#include <iostream>
#include <algorithm>
#include <sstream>
#include <deque>
#include <list>
#include <type_traits>
#include "Chrono.hpp"

class PmergeMe
{
    private:
            std::deque<std::deque<int> >     array;
            std::deque<std::deque<int> >     unsorted;
            std::deque<int>                  rest;
            std::deque<int>                  sequence;

            std::list<std::list<int> >       larray;
            std::list<std::list<int> >       lunsorted;
            std::list<int>                   lrest;
            std::list<int>                   lsequence;

            size_t                           pairSize;
            size_t                           lpairSize;
            Chronometer                      chronometer;
            double                           runTime;
            double                           lrunTime;
            
            int     parse(const std::string &input);
            void    fordJohnsonSort();
            void    pairUp();
            void    insert();
            void    binaryInsert(int num);
            void    initSequence();
            void    storeRest(std::deque<std::deque<int> >::iterator &end);
            void    swapPairs(std::deque<int> &first, std::deque<int> &second);
            void    printArray();
            void    addToSequence(std::deque<int> &queue);

            int     lparse(const std::string &input);
            void    lfordJohnsonSort();
            void    lpairUp();
            void    linsert();
            void    lbinaryInsert(int num);
            void    linitSequence();
            void    lstoreRest(std::list<std::list<int> >::iterator &end);
            void    lswapPairs(std::list<int> &first, std::list<int> &second);
            void    lprintArray();
            void    laddToSequence(std::list<int> &queue);
    public:
            PmergeMe(const std::string &input);
            PmergeMe(const PmergeMe &copy);
            PmergeMe &operator=(const PmergeMe &other);
            ~PmergeMe(){};
            void    getSequence();
            void    getUnsorted();
            void    getRunTime();

            void    lgetSequence();
            void    lgetUnsorted();
            void    lgetRunTime();
};
