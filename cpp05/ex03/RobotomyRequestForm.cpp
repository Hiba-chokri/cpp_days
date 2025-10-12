#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>  

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm parameterized constructor called with target: " << target << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &obj) {
        AForm::operator=(obj);
        target = obj.target;
    }
    return *this;
}

// Execute action - makes drilling noises and attempts robotomy (validation handled by base class)
void RobotomyRequestForm::executeAction() const {
    // Make drilling noises
    std::cout << "BZZZZZZZZ... DRILLING NOISES... BZZZZZZZZ..." << std::endl;
    std::cout << "VRRRRRR... MECHANICAL WHIRRING... VRRRRRR..." << std::endl;
    std::cout << "CLANK CLANK... ROBOTIC ASSEMBLY... CLANK CLANK..." << std::endl;
    
    // Initialize random seed (should be done once, but this is simple)
    srand(time(NULL));
    
    // 50% chance of success
    if (rand() % 2 == 0) {
        std::cout << "SUCCESS: " << target << " has been robotomized successfully!" << std::endl;
        std::cout << target << " is now a cyborg! Beep beep!" << std::endl;
    } else {
        std::cout << "FAILURE: The robotomy of " << target << " failed!" << std::endl;
        std::cout << "The procedure was unsuccessful. " << target << " remains fully human." << std::endl;
    }
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
