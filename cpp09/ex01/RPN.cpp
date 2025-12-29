#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &obj) {
    this->numbers = obj.numbers;
}

RPN &RPN::operator=(const RPN &obj) {
    if (this != &obj)
        this->numbers = obj.numbers;
    return *this;
}

bool RPN::isOperator(const std::string &token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidToken(const std::string &token) {

    if (token.length() == 1 && std::isdigit(token[0])) 
        return true;
    if (isOperator(token)) 
        return true;
    return false;
}

int RPN::operationCalcul(int a, int b, char op) {
    switch(op) 
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: Division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: Invalid operator");
    }
}

int RPN::eval(const std::string &expression) 
{
    std::istringstream string(expression);
    std::string token;
    
    while (string >> token)
    {
        if (!isValidToken(token)) 
            throw std::runtime_error("Error: Invalid token");
        if (std::isdigit(token[0])) 
        {
            int num = token[0] - '0';
            numbers.push(num);
        }
        else if (isOperator(token)) 
        {
            if (numbers.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            int result = operationCalcul(a, b, token[0]);
            numbers.push(result);
        }
    }
    if (numbers.size() != 1) 
        throw std::runtime_error("Error: Invalid expression");
    return numbers.top();
}