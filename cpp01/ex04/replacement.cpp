#include "replacement.hpp"

replace::replace(std::string &i, std::string &s1,
        std::string &s2) : infile(i), s1(s1), s2(s2){}

void replace::createNewFile()
{
        std::string outFile = replace::infile + ".replace";
        std::ofstream outfile(outFile.c_str());
}

replace::~replace()
{
        std::cout << "destroyed structure\n";
}