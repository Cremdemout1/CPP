/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:43:24 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 08:10:58 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
# include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::deque<T>::iterator				iterator;
        typedef typename std::deque<T>::const_iterator			const_iterator;
        typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
        typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;
        
        MutantStack() : std::stack<T>(){};
        MutantStack(const T* array, size_t size);
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack() {};
        iterator                begin() {return (this->c.begin());}
        iterator                end() {return (this->c.end());}
        
        const_iterator           begin() const {return (this->c.begin());}
        const_iterator           end() const {return (this->c.end());}
        
        reverse_iterator         rbegin() {return (this->c.rbegin());}
        reverse_iterator         rend() {return (this->c.rend());}
        
        const_reverse_iterator    rbegin() const {return (this->c.rbegin());}
        const_reverse_iterator    rend() const {return (this->c.rend());}
};