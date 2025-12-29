#include "BitcoinExchange.hpp"
#include<sstream>

BitcoinExchange::BitcoinExchange()
{
    std::cout<<"Constructor created"<<std::endl;
    
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

void BitcoinExchange::load_Database()
{
    std::ifstream file("data.csv");
    if (!file)
    {
        std::cerr<<"Error: could not open file."<<std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;
        
        if(!std::getline(ss, date, ','))
            continue;
        if(!std::getline(ss, rateStr, ','))
            continue;
       double ex_rate;
       std::stringstream(rateStr) >> ex_rate;
       btcDB[date] = ex_rate;
    }

}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0);
}

bool isValidDateValues(const std::string &date)
{
    int year, month, day;
    char dash1, dash2;
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (month < 1 || month > 12)
        return false;
    // Leap year
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}


bool isValidDateChars(const std::string &date)
{
    if (date.length() != 10)
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (!std::isdigit(date[i]))
                return false;
        }
    }
    return true;
}

double BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = btcDB.lower_bound(date);
    if (it != btcDB.end() && it->first == date)
        return it->second;
    if (it == btcDB.begin())
        return it->second;
    --it;
    return it->second;
}

void BitcoinExchange::processFileInput(std::string date, std::string valueStr)
{
    date.erase(date.find_last_not_of(" \t") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    double value;
    std::stringstream ss(valueStr);
    if (!(ss >> value))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return;
    }
    if (!isValidDateChars(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    if (!isValidDateValues(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }
    double rate = getRate(date);
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}