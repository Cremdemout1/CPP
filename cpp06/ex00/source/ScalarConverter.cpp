/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:07:58 by yohan             #+#    #+#             */
/*   Updated: 2025/02/22 10:12:46 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other; // not an instantiated object, so no copies are necessary
    return (*this);
}

ScalarConverter::~ScalarConverter() {};

/* ************************************************************************** */

enum types
{
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    SPECIAL,
    ERROR
};

static std::string validSpecials[5] =
{
    "nan",
    "-inff",
    "+inff",
    "-inf",
    "+inf"
};

bool    unprintableChar(char &ch)
{
    return (ch < 32 || ch == 127);
}

void trim(std::string &str)
{
    str.erase(0, str.find_first_not_of(" \t\n"));
    str.erase(str.find_last_not_of(" \t\n") + 1);
}

/* ************************************************************************** */

int getLiteralType(std::string &literal)
{
    size_t len = literal.length();
    size_t i = 0;
    bool hasDecimal = false;
    bool hasF = false;
    bool hasDigit = false;
    bool hasNonDigit = false;

    if (len <= 0)
        return (ERROR);                      // error of input
    
    for (i = 0; i < 5; i++)                  // special cases
        if (literal == validSpecials[i])
            return (SPECIAL);

    if (literal == "+.f" || literal == "-.f" || literal == ".f")
        return (ERROR);
        
    if (len == 1)
        if (!isdigit(literal[0]))
            return (CHAR);
    if (len > 1)
    {
        i = 0;
        while (i < len)                   // doubles
        {
            if (i != 0 && (literal[i] == '+' || literal[i] == '-')) 
                return (ERROR);
            if (isdigit(literal[i]))
                hasDigit = true;
            if (!isdigit(literal[i]) && literal[i] != '+' && literal[i] != '-' && literal[i] != 'f' && literal[i] != '.')
                hasNonDigit = true;
            if (literal[i] == '.')
            {
                if (hasDecimal)
                    return (ERROR);
                hasDecimal = true;
            }
            else if (literal[i] == 'f')
            {
                if (i != len - 1)
                    return (ERROR);
                hasF = true;
            }
            i++;
        } 
        if (hasF && !hasNonDigit)
            return (FLOAT);
        if (hasDecimal && !hasNonDigit)
            return (DOUBLE);
    }
    if (hasDigit && hasNonDigit)
        return (ERROR);
    return (INT);
}

void    printCharToAll(std::string &literal)
{
    int     intConversion = literal[0];
    double  doubleConversion = static_cast<double>(literal[0]);
    float   floatConversion = static_cast<float>(literal[0]);

    std::cout << "char: " <<  (unprintableChar(literal[0]) || intConversion < 0 ? "Non displayable" : literal) << std::endl;
    std::cout << "int: " << intConversion << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatConversion << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1 )<< doubleConversion << std::endl;
}

void    printIntToAll(std::string &literal)
{
    int  intConversion;
    try
    {
        intConversion = std::stoi(literal);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error in input\n";
        return ;
    }
    
    double  doubleConversion = static_cast<double>(intConversion);
    float   floatConversion = static_cast<float>(intConversion);
    char ch = static_cast<char>(intConversion);
    
    std::cout << "char: " <<  (unprintableChar(ch) || intConversion < 0 ? std::string("Non displayable") : std::string(1, ch)) << std::endl;
    std::cout << "int: " << intConversion << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatConversion << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1 )<< doubleConversion << std::endl;
}

void    printFloatToAll(std::string &literal)
{
    double  doubleConversion = std::stod(literal);
    if (doubleConversion < std::numeric_limits<int>::min() || doubleConversion > std::numeric_limits<int>::max())
    {
        std::cerr << "Error in input\n";
        return ;
    }
    float  floatConversion = static_cast<float>(doubleConversion);
    int   intConversion = static_cast<int>(floatConversion);
    char ch = static_cast<char>(intConversion);

    std::cout << "char: " <<  (unprintableChar(ch) || intConversion < 0 ? std::string("Non displayable") : std::string(1, ch)) << std::endl;
    std::cout << "int: " << intConversion << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatConversion << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1 )<< doubleConversion << std::endl;
}

void    printDoubleToAll(std::string &literal)
{
    double doubleConversion = std::stod(literal);
    if (doubleConversion < std::numeric_limits<int>::min() || doubleConversion > std::numeric_limits<int>::max())
    {
        std::cerr << "Error in input\n";
        return ;
    }
    float floatConversion = std::stof(literal);
    floatConversion = static_cast<double>(doubleConversion);
    int intConversion = static_cast<int>(doubleConversion);
    char ch = static_cast<char>(intConversion);
    
    std::cout << "char: " <<  (unprintableChar(ch) || intConversion < 0 ? std::string("Non displayable") : std::string(1, ch)) << std::endl;
    std::cout << "int: " << intConversion << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatConversion << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1 )<< doubleConversion << std::endl;
}

void    printSpecialToAll(std::string &literal)
{
    std::string charConversion;
    std::string intConversion;
    std::string doubleConversion;
    std::string floatConversion;
    
    charConversion = "impossible";
    intConversion = charConversion;
    if (literal == "nan")
    {
        floatConversion = "nanf";
        doubleConversion = validSpecials[0];
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        floatConversion = "-inf";
        doubleConversion = floatConversion;
    }
    else if (literal == "+inff" || literal == "+inf")
    {
        floatConversion = "inf";
        doubleConversion = floatConversion;
    }
    std::cout << "char: " << charConversion << std::endl;
    std::cout << "int: " << intConversion << std::endl;
    std::cout << "float: " << floatConversion << std::endl;
    std::cout << "double: " << doubleConversion << std::endl;
}
/* ************************************************************************** */

void    printType(int type)
{
    if (type == INT)
        std::cout << "INT\n";
    else if (type == FLOAT)
        std::cout << "FLOAT\n";
    else if (type == CHAR)
        std::cout << "CHAR\n";
    else if (type == SPECIAL)
        std::cout << "SPECIAL\n";
    else if (type == DOUBLE)
        std::cout << "DOUBLE\n";
    else
        std::cout << "ERROR\n";
}

void ScalarConverter::convert(const std::string &literal)
{
    std::string value = literal;        // must be used to change value of literal as it is a constant
    
    trim(value);
    int type = getLiteralType(value);
    // printType(type);
    if (type == SPECIAL)
        printSpecialToAll(value);
    else if (type == CHAR)
        printCharToAll(value);
    else if (type == INT)
        printIntToAll(value);
    else if (type == DOUBLE)
        printDoubleToAll(value);
    else if (type == FLOAT)
        printFloatToAll(value);
    else
    {
        std::cout << "Error in input\n";
        return ;
    }
}