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
        void load_Database();
        void processFileInput(std::string date, std::string valueStr);
        double getRate(const std::string &date) const;
        
};

#endif
