/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:33:11 by yohan             #+#    #+#             */
/*   Updated: 2025/02/06 13:23:09 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

class ReplaceFile
{
    private:
    std::string inputFile;
    std::string outputFile;
    std::string fileContent;
    std::string s1;
    std::string s2;
    void    readFile();
    void    replaceWord();
    void    writeToFile();
    public:
    ReplaceFile (std::string &inputfile, std::string &s1, std::string &s2);
    void    Replace();
    void    read();
};