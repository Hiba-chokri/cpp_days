#include "Span.hpp"

int main() {
    try {
        Span sp(5); // Span that can hold 5 numbers

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Trying to add a 6th number should throw an exception
        std::cout << "Adding another number..." << std::endl;
        sp.addNumber(42); // This should fail
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing with a large random range
    try {
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(i);
        }
        std::cout << "Shortest Span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span in bigSpan: " << bigSpan.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}