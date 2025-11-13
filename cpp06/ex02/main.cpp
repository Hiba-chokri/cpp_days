#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Base* ptr = generate();

    std::cout << "Identify using pointer: ";
    identify(ptr);

    std::cout << "Identify using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}