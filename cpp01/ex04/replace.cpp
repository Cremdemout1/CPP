/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:46:42 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 13:38:31 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

ReplaceFile::ReplaceFile(std::string &Inputfile, std::string &s1, std::string &s2)
{
    this->inputFile = Inputfile;
    this->outputFile = inputFile + ".replace";
    this->s1 = s1;
    this->s2 = s2;
};

void    ReplaceFile::readFile()
{
    std::ifstream infile(inputFile.c_str());
    std::stringstream buffer;
    if (!infile)
    {
        std::cout << "Error: Unable to open " << inputFile << std::endl;
        return ;
    }
    buffer << infile.rdbuf();
    infile.close();
    fileContent = buffer.str();
}

void    ReplaceFile::writeToFile()
{
    std::ofstream outfile(outputFile.c_str());
    
    if (!outfile.is_open())
    {
        std::cout << "Error: Unable to create " << outputFile << std::endl;
        return ;
    }
    outfile << fileContent;
    outfile.close();
}

void   ReplaceFile::replaceWord()
{
    size_t i = 0;
    size_t pos = 0;
    std::string result;
    if (s1.empty())
    {
        std::cout << "Word to ReplaceFile is empty\n";
        return ;
    }
    while ((pos = fileContent.find(s1, i)) != std::string::npos)
    {
        result.append(fileContent, i, pos - i);
        result.append(s2);
        i = pos + s1.length();
    }
    result.append(fileContent, i, std::string::npos);
    fileContent = result;
}

void ReplaceFile::Replace()
{
    ReplaceFile::readFile();
    ReplaceFile::replaceWord();
    ReplaceFile::writeToFile();
}

void ReplaceFile::read()
{
    ReplaceFile::readFile();
}