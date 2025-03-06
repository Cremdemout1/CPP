/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:28:35 by yohan             #+#    #+#             */
/*   Updated: 2025/03/01 13:04:38 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/predictor.hpp"
#include <string>


//              2011-04-05,0.77

            // struct Date
            // {
            //     int year, month, day;
            // };

            // struct dayAndPrice
            // {
            //     Date    date;
            //     float   value;
            // };
bool    compare(dayAndPrice &a, dayAndPrice&b)
{
    if (a.date.year != b.date.year)
        return a.date.year < b.date.year;
    if (a.date.month != b.date.month)
        return a.date.month < b.date.month;
    if (a.date.day != b.date.day)
        return a.date.day < b.date.day;
    return true;
}

void    Predictor::fillContainer()
{
    std::string line;
    std::fstream fd(inputFile);
    dayAndPrice temp;
    std::getline(fd, line);
    while (std::getline(fd, line))
    {
        try
        {
            temp = separateInfo(line);
            container.push_back(temp);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    //std::sort(container.begin(), container.end(), compare);
}

std::vector<std::string>    split(std::string str, std::string &delimiter)
{
    std::vector<std::string>    vect;
    size_t                      pos = str.find(delimiter);
    size_t                      len = delimiter.length();
    
    while (pos != std::string::npos)
    {
        vect.push_back(str.substr(0, pos));
        str.erase(0, pos + len);
        pos = str.find(delimiter);
    }
    vect.push_back(str);
    return (vect);
}

float   checkValue(std::string value)
{
    float temp = std::stof(value);
    if (temp < 0)
        throw std::runtime_error("Error: not a positive number.");
    else if (temp > 1000)
        throw std::runtime_error("Error: Too large a number.");
    return (temp);
}

dayAndPrice separateInfo(std::string &info)
{
    dayAndPrice node;
    std::string delimiter = "|";
    std::vector<std::string> splitted = split(info, delimiter);
    node.date = separateDate(splitted[0]);
    node.value = checkValue(splitted[1]);
    return (node);
}

bool isValidDate(int month, int day)
{
    if (month < 1 || month > 12)
        return false;
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (day >= 1 && day <= daysInMonth[month - 1]);
}

Date        separateDate(std::string &date)
{
    Date actual;
    std::string delimiter = "-";
    std::vector<std::string> splitted = split(date, delimiter);

    try
    {
        actual.year = std::stoi(splitted[0]);
        actual.month = std::stoi(splitted[1]);
        actual.day = std::stoi(splitted[2]);
        if (!isValidDate(actual.month, actual.day))
        {
            std::string err = "Error: bad input => " + date;
            throw std::runtime_error(err);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (actual);
}

bool compareDates(const Date& lhs, const Date& rhs) {
    if (lhs.year != rhs.year)
        return lhs.year < rhs.year;
    if (lhs.month != rhs.month)
        return lhs.month < rhs.month;
    return lhs.day < rhs.day;
}

void Predictor::evaluate(std::string date, float value)
{
    Date realDate = separateDate(date);
    dayAndPrice answer = {{0, 0, 0}, 0.0};
    std::vector<dayAndPrice>::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
    {
        if (it->date == realDate)
        {
            answer = *it;
            break;
        }
        else if (it->date < realDate && answer.date < it->date)
            answer = *it;
    }
    if (answer.date.year == 0)
    {
        std::cout << "No valid previous date found for "
                  << date << " Defaulting to first iteration" << std::endl;
        it = container.begin();
        answer = *it;
    }
    std::cout << answer.date.year << "-"
              << (answer.date.month < 10 ? "0" : "") << answer.date.month << "-"
              << (answer.date.day < 10 ? "0" : "") << answer.date.day
              << " => " << answer.value
              << " = " << answer.value * value << std::endl;
}
