#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        
    }
    return *
    this;
}

bool PmergeMe::isValidNumber(const std::string &str) {
    if (str.empty()) 
        return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::validateInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::invalid_argument("Invalid number: " + arg);
        int num;
        std::stringstream ss(arg);
        ss >> num;
        _vectorData.push_back(num);
        _dequeData.push_back(num);
    }
}
