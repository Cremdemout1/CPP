/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:57:00 by yohan             #+#    #+#             */
/*   Updated: 2025/03/08 11:36:37 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string &input) : array(), unsorted(), rest(), sequence(), larray(), lunsorted(), lrest(), lsequence(), pairSize(1), lpairSize(1), runTime(0), lrunTime(0)
{
    try
    {
        if (parse(input))
            return ;
        chronometer.start();
        fordJohnsonSort();
        runTime = chronometer.elapsed();
        if (lparse(input))
        return ;
        chronometer.start();
        lfordJohnsonSort();
        lrunTime = chronometer.elapsed();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->array = other.array;
        this->rest = other.rest;
        this->sequence = other.sequence;
        this->pairSize = other.pairSize;
        this->larray = other.larray;
        this->lrest = other.lrest;
        this->lsequence = other.lsequence;
    }
    return (*this);
}

/* ____________________________________________________________ */

int PmergeMe::parse(const std::string &input)
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
            std::deque<int> singleElementDeque;
            singleElementDeque.push_back(std::stoi(token));
            array.push_back(singleElementDeque);
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Invalid number format");
            return 1;
        }
    }
    unsorted = array;
    if (array.size() == 2)
    {
        swapPairs(array[0], array[1]);
        addToSequence(array[0]);
        addToSequence(array[1]);
        return 1;
    }
    else if (array.size() == 1)
    {
        addToSequence(array[0]);
        return 1;
    }

    return 0;
}

void PmergeMe::storeRest(std::deque<std::deque<int> >::iterator &end)
{
    for (; end != array.end(); ++end)
        for (std::deque<int>::iterator it = (*end).begin(); it != (*end).end(); ++it)
            rest.push_back(*it);
}

void PmergeMe::pairUp()
{
    pairSize *= 2;
    std::deque<std::deque<int> > newArray;
    std::deque<std::deque<int> >::iterator it = array.begin();
    std::deque<std::deque<int> >::iterator end;

    if (array.size() % pairSize == 0)
        end = array.end();
    else
        end = array.begin() + (array.size() / pairSize) * pairSize;
    while (it != end)
    {
        if (std::next(it) != array.end())
            swapPairs(*it, *std::next(it));
        std::deque<int> pair;
        size_t elementsAdded = 0;
        while (elementsAdded < pairSize && it != array.end())
        {
            pair.insert(pair.end(), it->begin(), it->end());
            elementsAdded += it->size();
            ++it;
        }
        newArray.push_back(pair);
    }
    storeRest(end);
    array = newArray;
}

void PmergeMe::swapPairs(std::deque<int> &first, std::deque<int> &second)
{
    std::deque<int> temp;

    if (first.empty() || second.empty())
        return ;
    if (second.back() < first.back())
        std::swap(first, second);
}

int getLastElement(std::deque<int> &queue)
{
    int temp = queue.back();
    queue.pop_back();
    return (temp);
}

void PmergeMe::initSequence()
{
    int temp = array.front().front();
    array.front().pop_front();
    sequence.push_front(temp);

    std::deque<std::deque<int> >::iterator it = array.begin();
    while (it != array.end())
    {
        sequence.push_back(getLastElement(*it));
        ++it;
    }
}

void PmergeMe::binaryInsert(int num)
{
    std::deque<int>::iterator pos = std::lower_bound(sequence.begin()
        , sequence.end(), num);
    sequence.insert(pos, num);
}

void PmergeMe::insert()
{
    std::deque<int>::iterator i;
    if (array.size() != 0) //seg fault fix
    {
        initSequence();
        std::deque<std::deque<int> >::iterator it = array.begin();
        for (; it != array.end(); ++it)
            for (i = it->begin(); i != it->end(); ++i)
                binaryInsert(*i);
    }

    for (i = rest.begin(); i != rest.end(); ++i)
        binaryInsert(*i);
}

void PmergeMe::fordJohnsonSort()
{
    size_t size = array.size();
    while (size > pairSize * 2)
        pairUp(); // pairs and merges integers and arrays of integers (pairs of pairs and such)
    if (array.size() > 1)
        if (!array[0].empty() && !array[1].empty())
            swapPairs(array[0], array[1]);
    insert();
}

void PmergeMe::printArray()
{
    std::deque<std::deque<int> >::iterator subDeque;
    std::deque<int>::iterator i;
    for (subDeque = array.begin(); subDeque != array.end(); ++subDeque)
        for (i = subDeque->begin(); i != subDeque->end(); i++)
            std::cout << *i << " ";
    std::cout << std::endl;
}

void    PmergeMe::addToSequence(std::deque<int> &queue)
{
    std::deque<int>::iterator it = queue.begin();

    for (; it != queue.end(); ++it)
        sequence.push_back(*it);
}

void    PmergeMe::getSequence()
{
    std::deque<int>::iterator it = sequence.begin();
    std::cout << "Sorted sequence: ";
    for (; it != sequence.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::getUnsorted()
{
    std::deque<std::deque<int> >::iterator it = unsorted.begin();
    std::deque<int>::iterator i;

    std::cout << "Unsorted sequence: ";
    for (; it != unsorted.end(); ++it)
        for (i = it->begin(); i != it->end(); ++i)
            std::cout << *i << " ";
    std::cout << std::endl;
}

void    PmergeMe::getRunTime()
{
    std::cout << std::fixed << "Sorting deque runTime: " << runTime << "s\n";
}
