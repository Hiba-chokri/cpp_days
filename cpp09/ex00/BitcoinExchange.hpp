#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include<iostream>
#include<fstream>
#include<map>
#include<string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> btcDB;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
};

#endif
