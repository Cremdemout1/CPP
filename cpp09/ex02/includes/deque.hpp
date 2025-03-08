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
#include <type_traits>

class PmergeMe
{
    private:
            std::deque<std::deque<int> >     array;
            std::deque<std::deque<int> >     unsorted;
            std::deque<int>                  rest;
            std::deque<int>                  sequence;
            size_t                           pairSize;
            
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
    public:
            PmergeMe(const std::string &input);
            PmergeMe(const PmergeMe &copy);
            PmergeMe &operator=(const PmergeMe &other);
            ~PmergeMe(){};
            void    getSequence();
            void    getUnsorted();
};
