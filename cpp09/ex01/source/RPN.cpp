/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:53:51 by yohan             #+#    #+#             */
/*   Updated: 2025/03/07 11:07:07 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

void    RPN::calculate(const char op)
{
    float res = 0;
    float b = operation.top();
    operation.pop();
    float a = operation.top();
    operation.pop();
    switch (op)
    {
        case '*':
            res = (a * b);
            break ;
        case '/':
            res = (a / b);
            break ;
        case '+':
            res = (a + b);
            break ;
        case '-':
            res = (a - b);
            break ;
        default:
            throw std::runtime_error("Error: Unknown operator");
    }
    operation.push(res);
}

void    RPN::runRPN(const std::string &str)
{
    std::stringstream ss(str);
    std::string token;
    float temp;
     
    while (std::getline(ss, token, ' '))
    {
        if (token[0] == '*' || token[0] == '/' || token[0] == '+' || (token[0] == '-' && !token[1]))
            calculate(token[0]);
        else
        {
            temp = std::atof(token.c_str());
            if (temp >= 10 || temp <= -10)
                throw std::runtime_error("Invalid argument");
            operation.push(temp);
        }
    }
    std::cout << operation.top();
}

void    RPN::parseInput(const std::string &input)
{
    std::string operators = "+-*/\n ";
    std::string num = "0123456789";
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '-'  && i + 1 < input.length()  && num.find(input[i + 1]) != std::string::npos)
            continue ;
        else if (input[i] == '+' || input[i] == '/' || input[i] == '*')
        {
            if (i + 1 < input.length() && input[i + 1] != ' ' && input[i + 1] != '\n' && input [i + 1] != '\0')
                throw std::runtime_error("Invalid Input"); 
        }
        else if (operators.find(input[i]) == std::string::npos
            && num.find(input[i]) == std::string::npos)
            throw std::runtime_error("Invalid Input");
    }
}

RPN::RPN(const std::string &input)
{
    try
    {
        parseInput(input);
        runRPN(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->result = other.result;
        this->operation = other.operation;
    }
    return (*this);
}

RPN::~RPN(){}
