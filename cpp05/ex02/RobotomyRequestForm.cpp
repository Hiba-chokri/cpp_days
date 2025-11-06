#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>  

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {
    static bool rand = false;
    if (!rand) {
        std::srand(std::time(NULL));
        rand = true;
    }
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm parameterized constructor called with target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &obj) {
        AForm::operator=(obj);
        target = obj.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
		throw (FormNotSignedException());
	if (executor.getGrade() > getGradeToExecute())
        throw FormGradeTooLowException();
    // Make drilling noises
    std::cout << "BZZZZZZZZ... DRILLING NOISES... BZZZZZZZZ..." << std::endl;

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
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}