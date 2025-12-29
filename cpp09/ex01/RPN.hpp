#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>


class RPN
{
    private:
        std::stack<int> numbers;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        bool isOperator(const std::string &token);
        int operationCalcul(int a, int b, char op);
        bool isValidToken(const std::string &token);
        int eval(const std::string &expression);

};
#endif