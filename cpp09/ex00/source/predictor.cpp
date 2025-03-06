/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predictor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:08:55 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 10:51:24 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/predictor.hpp"

Predictor::Predictor() : inputFile(nullptr) {}

Predictor::Predictor(const std::string &inputfile) : inputFile(inputfile)
{
    try
    {
        fileCheck();
        fillContainer();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


Predictor::Predictor(const Predictor &copy)
{
    *this = copy;
}

Predictor &Predictor::operator=(const Predictor &other)
{
    if (this != &other)
    {
        this->container = other.container;
        this->inputFile = other.inputFile;
    }
    return (*this);
}

Predictor::~Predictor() {}

void    Predictor::setFileName(const std::string &filename)
{
    this->inputFile = filename;
    try
    {
        fileCheck();
        fillContainer();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void    Predictor::fileCheck()
{
    std::ifstream fd(inputFile);
    if (!fd.is_open())
        throw std::runtime_error("Invalid file, please enter new filename");
}
