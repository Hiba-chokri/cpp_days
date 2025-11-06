#include "Bureaucrat.hpp"

int main() {
    std::cout << " TEST 1: Valid Bureaucrat Creation" << std::endl;
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl; // should print: Alice, bureaucrat grade 42.
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "TEST 2: Invalid Bureaucrat" << std::endl;
    try {
        Bureaucrat b2("Bob", 151); // invalid → throws GradeTooLowException
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << " TEST 3: Invalid Bureaucrat (Too High) " << std::endl;
    try {
        Bureaucrat b3("Charlie", 0); // invalid → throws GradeTooHighException
        std::cout << b3 << std::endl; // won't run
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: incrementGrade and decrementGrade ===" << std::endl;
    try {
        Bureaucrat b4("Diana", 2);
        std::cout << b4 << " (created)" << std::endl;

        // incrementGrade (2 -> 1): OK
        b4.incrementGrade();
        std::cout << b4 << " (after incrementGrade)" << std::endl;

        // incrementGrade (1 -> 0): Invalid → throws GradeTooHighException
        b4.incrementGrade(); 
        std::cout << b4 << " (after second incrementGrade)" << std::endl; // won't run
    }
    catch (std::exception &e) {
        std::cout << "Exception caught while incrementGradeing: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: decrementGrade Beyond Limit ===" << std::endl;
    try {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << " (created)" << std::endl;

        // Decrement (150 -> 151): invalid → throws GradeTooLowException
        b5.decrementGrade();
        std::cout << b5 << " (after decrementGrade)" << std::endl; // won't run
    }
    catch (std::exception &e) {
        std::cout << "Exception caught while decrementGradeing: " << e.what() << std::endl;
    }

    std::cout << " TEST 6: Copy & Assignment ===" << std::endl;
    try {
        Bureaucrat original("Frank", 10);
        Bureaucrat copy(original); // copy constructor
        Bureaucrat assigned("Greg", 100);
        assigned = original; // assignment operator

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught during copy/assign: " << e.what() << std::endl;
    }

    std::cout << "\n=== END OF TESTS ===" << std::endl;
    return 0;
}

