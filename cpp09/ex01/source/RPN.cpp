/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:53:51 by yohan             #+#    #+#             */
/*   Updated: 2025/03/03 23:19:59 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

float    RPN::calculate(const char operator)
{
    float b = operation.top();
    operation.pop();
    float a = operation.top();
    operation.pop();
    switch (operator)
    {
        case '*':
            return (a * b);
        case '/':
            return (a / b);
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        break;
    
    default:
        break;
    }
    return (result);
}

void    RPN::runRPN(const std::string &str, std::string &delimiter)
{
    std::stack<std::string> stack;
    std::stringstream ss(str);
    std::string token;
    float temp;
    
    while (std::getline(ss, token, delimiter[0]))
    {
        if (token[0] == 'x' || token[0] == '/' || token[0] == '+' || token[0] == '-')
            calculate(token[0]);
        temp = stof(token);
        if (temp >= 10 || temp <= -10)
            throw std::runtime_error("Invalid argument");
        stack.push(stof(temp));
    }
}

RPN::RPN(std::string &input)
{
    try
    {
        parseInput(input);
        
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
}
RPN::~RPN();


void    parseInput(std::string &input)
{
    std::string operators = "+-*/";
    for (int i = 0; i < input.length(); i++)
        if (!isnumber(input[i]) || !operators.find(input[i]))
            throw std::runtime_error("Invalid Input");
}