#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm parameterized constructor called with target: " << target << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &obj) {
        AForm::operator=(obj);
        target = obj.target;
    }
    return *this;
}

// Execute action - announces presidential pardon (validation handled by base class)
void PresidentialPardonForm::executeAction() const {
    // Announce the presidential pardon
    std::cout  << target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
