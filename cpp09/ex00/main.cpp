#include"BitcoinExchange.hpp"
#include<sstream>

int main(int argc, char *argv[])
{
    BitcoinExchange Bit;

    Bit.load_Database();
    if(argc != 2)
    {
        std::cerr<<"Error: could not find the input file."<<std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    if(!input.is_open())
    {
        std::cerr<<"Error: could not open file."<<std::endl;
        return 1;
    }
    std::string line;
    std::string date, val;
    std::getline(input, line);
    while(std::getline(input, line))
    {
        std::stringstream ss(line);
        if(!std::getline(ss, date, '|'))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if(!std::getline(ss, val, '|'))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        Bit.processFileInput(date, val);
    }
    return 0;

}