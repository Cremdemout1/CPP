/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lArray.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:35:49 by yohan             #+#    #+#             */
/*   Updated: 2025/03/08 11:26:12 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int PmergeMe::lparse(const std::string &input)
{
    std::string validChar = "0123456789 \n";
    for (size_t i = 0; i < input.length(); i++)
        if (validChar.find(input[i]) == std::string::npos)
            throw std::runtime_error("Invalid argument");

    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        try
        {
            std::list<int> singleElementDeque;
            singleElementDeque.push_back(std::stoi(token));
            larray.push_back(singleElementDeque);
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Invalid number format");
            return 1;
        }
    }
    lunsorted = larray;
    std::list<std::list<int> >::iterator it = larray.begin();
    if (larray.size() == 2)
    {
        std::list<std::list<int> >::iterator next_it = it;
        std::advance(next_it, 1);
        lswapPairs(*it, *next_it);
        laddToSequence(*it);
        laddToSequence(*next_it);
        return 1;
    }
    else if (larray.size() == 1)
    {
        laddToSequence((*it));
        return 1;
    }
    return 0;
}

void PmergeMe::lstoreRest(std::list<std::list<int> >::iterator &end)
{
    for (; end != larray.end(); ++end)
        for (std::list<int>::iterator it = (*end).begin(); it != (*end).end(); ++it)
            lrest.push_back(*it);
}

void PmergeMe::lpairUp()
{
    lpairSize *= 2;
    std::list<std::list<int> > newArray;
    std::list<std::list<int> >::iterator it = larray.begin();
    std::list<std::list<int> >::iterator end;

    if (larray.size() % lpairSize == 0)
        end = larray.end();
    else
    {
        end = larray.begin();
        std::advance(end, (larray.size() / lpairSize) * lpairSize);
    }
    while (it != end)
    {
        if (std::next(it) != larray.end())
            lswapPairs(*it, *std::next(it));
        std::list<int> pair;
        size_t elementsAdded = 0;
        while (elementsAdded < lpairSize && it != larray.end())
        {
            pair.insert(pair.end(), it->begin(), it->end());
            elementsAdded += it->size();
            ++it;
        }
        newArray.push_back(pair);
    }
    lstoreRest(end);
    larray = newArray;
}

void PmergeMe::lswapPairs(std::list<int> &first, std::list<int> &second)
{
    std::list<int> temp;

    if (first.empty() || second.empty())
        return ;
    if (second.back() < first.back())
        std::swap(first, second);
}

int getLastElement(std::list<int> &queue)
{
    int temp = queue.back();
    queue.pop_back();
    return (temp);
}

void PmergeMe::linitSequence()
{
    int temp = larray.front().front();
    larray.front().pop_front();
    lsequence.push_front(temp);

    std::list<std::list<int> >::iterator it = larray.begin();
    while (it != larray.end())
    {
        lsequence.push_back(getLastElement(*it));
        ++it;
    }
}

void PmergeMe::lbinaryInsert(int num)
{
    std::list<int>::iterator pos = std::lower_bound(lsequence.begin()
        , lsequence.end(), num);
    lsequence.insert(pos, num);
}

void PmergeMe::linsert()
{
    std::list<int>::iterator i;
    if (larray.size() != 0) //seg fault fix
    {
        linitSequence();
        std::list<std::list<int> >::iterator it = larray.begin();
        for (; it != larray.end(); ++it)
            for (i = it->begin(); i != it->end(); ++i)
                lbinaryInsert(*i);
    }

    for (i = lrest.begin(); i != lrest.end(); ++i)
        lbinaryInsert(*i);
}

void PmergeMe::lfordJohnsonSort()
{
    size_t size = larray.size();
    std::list<std::list<int> >::iterator it = larray.begin();
    std::list<std::list<int> >::iterator next_it = larray.begin();
    std::advance(next_it, 1);
    while (size > lpairSize * 2)
        lpairUp(); // pairs and merges integers and arrays of integers (pairs of pairs and such)
    if (larray.size() > 1)
        if (!it->empty() && !next_it->empty())
            lswapPairs(*it, *next_it);
    linsert();
}

void PmergeMe::lprintArray()
{
    std::list<std::list<int> >::iterator subDeque;
    std::list<int>::iterator i;
    for (subDeque = larray.begin(); subDeque != larray.end(); ++subDeque)
        for (i = subDeque->begin(); i != subDeque->end(); i++)
            std::cout << *i << " ";
    std::cout << std::endl;
}

void    PmergeMe::laddToSequence(std::list<int> &queue)
{
    std::list<int>::iterator it = queue.begin();

    for (; it != queue.end(); ++it)
        lsequence.push_back(*it);
}

void    PmergeMe::lgetSequence()
{
    std::list<int>::iterator it = lsequence.begin();
    std::cout << "Sorted sequence: ";
    for (; it != lsequence.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::lgetUnsorted()
{
    std::list<std::list<int> >::iterator it = lunsorted.begin();
    std::list<int>::iterator i;

    std::cout << "Unsorted sequence: ";
    for (; it != lunsorted.end(); ++it)
        for (i = it->begin(); i != it->end(); ++i)
            std::cout << *i << " ";
    std::cout << std::endl;
}

void    PmergeMe::lgetRunTime()
{
    std::cout << std::fixed << "Sorting list runTime: " << lrunTime << "s\n";
}
