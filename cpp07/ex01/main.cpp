#include "iter.hpp"
#include <iostream>
#include <string.h>


void incrementInt(int& x) {
    ++x;
}

void printInt(int const &x) {
    std::cout << x << " ";
}

void printString(std::string const &str) {
    std::cout << str << " ";
}

void printDouble(double const &d) {
    std::cout << d << " ";
}

int main()
{
    int values[] = {5, 10, 15, 20, 25};
    size_t valuesSize = 5;
     std::cout << "  Original: ";
    iter(values, valuesSize, printInt);
    std::cout << std::endl;
    iter(values, valuesSize, incrementInt);
    std::cout << "  +1:       ";
    iter(values, valuesSize, printInt);
    std::cout << std::endl << std::endl;

    std::cout << " Double array" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleSize = 5;
    
    iter(doubleArray, doubleSize, printDouble);
    std::cout << std::endl;

    std::cout << "TEST 3: String array" << std::endl;
    std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
    size_t stringSize = 4;
    
    std::cout << "  Strings: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl << std::endl;
}
