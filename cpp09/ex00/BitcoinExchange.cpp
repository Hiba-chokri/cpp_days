#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream exchange("data.csv");
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        btcDB = other.btcDB;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout<<"Destructor created"<<std::endl;
}