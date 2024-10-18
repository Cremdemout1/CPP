#ifndef REP_H
#define REP_H

#include <iostream>
#include <string>
#include <fstream>

class replace
{
    private:
    std::string infile;
    std::string outfile;
    std::string s1;
    std::string s2;
    std::string data;
    public:

    replace(std::string &i, std::string &s1, std::string &s2);
    void createNewFile();
    std::string newContent();
    ~replace();
};

#endif