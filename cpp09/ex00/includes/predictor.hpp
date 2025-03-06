/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predictor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 08:43:43 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 12:35:40 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

struct Date
{
    int year, month, day;
    bool operator<(const Date &other) const
    {
        if (year != other.year)
            return (year < other.year);
        if (month != other.month)
            return (month < other.month);
        return (day < other.day);
    }
    bool operator<=(const Date &other) const
    {
        return (*this < other || *this == other);
    }
    bool operator==(const Date &other) const 
    {
        return (year == other.year && month == other.month && day == other.day);
    }
};

struct dayAndPrice
{
    Date    date;
    float   value;

    bool operator==(const dayAndPrice& other) const
    {
        return date == other.date;
    }

    bool operator<=(const dayAndPrice& other) const
    {
        return (this->date < other.date || this->date == other.date);
    }

    bool operator<(const dayAndPrice& other) const
    {
        return this->date < other.date;
    }
};


class Predictor
{
    private:
        std::string              inputFile;
        std::vector<dayAndPrice> container;
        void    fileCheck();
        void    fillContainer();
    public:
        Predictor(); // add setFile later
        Predictor(const std::string &inputfile);
        Predictor(const Predictor &copy);
        Predictor &operator=(const Predictor &other);
        ~Predictor();
        void    setFileName(const std::string &filename);
        void    evaluate(std::string date, float value);
};

dayAndPrice separateInfo(std::string &info);
Date        separateDate(std::string &date);