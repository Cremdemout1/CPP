/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:53:28 by yohan             #+#    #+#             */
/*   Updated: 2025/02/26 17:21:19 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), arraySize(0) {};

template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n)
{
    array = new T[arraySize]();
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    *this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] array;
        arraySize = other.arraySize;
        array = new T[arraySize]();
        for (size_t i = 0; i < arraySize; i++)
            array[i] = other.array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= arraySize)
        throw std::out_of_range("index out of bounds");
    return (array[index]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}
template <typename T>
size_t  Array<T>::size()
{
    return (arraySize);
}