#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <climits>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
        unsigned int count;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void printNumbers();
        void fillRandomNumbers(int *numbers, unsigned int size);
};


#endif