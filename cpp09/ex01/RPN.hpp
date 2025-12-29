#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>


class RPN
{
    private:
        std::stack<double> numbers;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        bool isOperator(const std::string &token);
        double operationCalcul(int a, int b, char op);
        bool isValidToken(const std::string &token);
        void eval(const std::string &expression);

};