
#include "replacement.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        return (std::cout << "not the right amount of arguments\n", 1);

    std::ifstream input(argv[1]);
    if (!input)
    {
        std::cout << "invalid input file\n";
        return (1);
    }
    
    std::string infile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    replace Replace(infile, s1, s2);
    Replace.createNewFile();
    return (0);
}