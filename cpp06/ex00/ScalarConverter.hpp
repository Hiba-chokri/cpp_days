#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();


    public:
        static void	convertToChar(int input);
        static void	convertToInt(std::string input);
        static void	convertToFloat(std::string input);
        static void	convertToDouble(std::string input);

        static void	convert(std::string input);
};