#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { (void)obj; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) { (void)obj; return *this; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter::convertToChar(int input) {
    if (input < 0 || input > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(input)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
    }
}

void ScalarConverter::convertToInt(std::string input) {
    try {
        size_t pos;
        long value = std::stol(input, &pos);
        if (pos != input.length() || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
            throw std::out_of_range("impossible");
        }
        int intValue = static_cast<int>(value);
        std::cout << "int: " << intValue << std::endl;
        convertToChar(intValue);
    } catch (const std::exception &e) {
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
    }

    void ScalarConverter::convertToFloat(std::string input) {
    try {
        size_t pos;
        float value = std::stof(input, &pos);
        if (pos != input.length() && !(input == "nanf" || input == "+inff" || input == "-inff")) {
            throw std::invalid_argument("impossible");
        }
        std::cout << "float: " << value << "f" << std::endl;
        convertToInt(std::to_string(static_cast<int>(value)));
    } catch (const std::exception &e) {
        std::cout << "float: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConverter::convertToDouble(std::string input) {
    try {
        size_t pos;
        double value = std::stod(input, &pos);
        if (pos != input.length() && !(input == "nan" || input == "+inf" || input == "-inf")) {
            throw std::invalid_argument("impossible");
        }
        std::cout << "double: " << value << std::endl;
        convertToInt(std::to_string(static_cast<int>(value)));
    } catch (const std::exception &e) {
        std::cout << "double: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "char: impossible" << std::endl;
    }
}