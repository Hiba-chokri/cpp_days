#include "Span.hpp"

Span::Span(unsigned int n){
    N = n;
    count = 0;
    std::cout << "Span of size " << n << " constructed." << std::endl;
}

Span::~Span(){
    std::cout << "Span destructed." << std::endl;
}

Span::Span(const Span &obj)
{
    *this = obj;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
    }
    return *this;
}
void Span::addNumber(int number){
    if (N > count)
    {
        numbers.push_back(number);
        count++;
    }
    else
    {
        throw std::runtime_error("Span is full");
    }
}
void Span::fillRandomNumbers(int *numbers, unsigned int size){
    for (unsigned int i = 0; i < size; i++)
    {
        if(i < N)
            addNumber(numbers[i]);
    }
}
int Span::shortestSpan(){
    if (count < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    int minSpan = INT_MAX;
    int tmp = 0;
    std::sort(numbers.begin(), numbers.end());
    for (unsigned int i = 0; i < N - 1; i++)
    {
        tmp = numbers[i + 1] - numbers[i];
        if (tmp < minSpan)
            minSpan = tmp;
    }
    return minSpan;
}

int Span::longestSpan(){
    if (count < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::sort(numbers.begin(), numbers.end());
    return numbers[N - 1] - numbers[0];
}
void Span::printNumbers()
{
        for (unsigned int i = 0; i < numbers.size(); i++)
     {
            std::cout << numbers[i] << " ";
    }
        std::cout << std::endl;
}