#include "AForm.hpp"

const char	*FormGradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*FormGradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

const char	*FormNotSignedException::what() const throw()
{
	return ("Form::FormNotSignedException");
}

const char	*FormFileException::what() const throw()
{
	return ("Form::FormFileException: File could not be opened.");
}

// Default constructor
AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
    std::cout << "AForm parameterized constructor called" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm& obj) 
    : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

// Assignment operator
AForm& AForm::operator=(const AForm& obj) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &obj) {
        // Note: name, gradeToSign, and gradeToExecute are const, so they can't be reassigned
        // Only isSigned can be copied
        isSigned = obj.isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

// Getters
std::string AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

// beSigned method
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign) {
        throw FormGradeTooLowException();
    }
    isSigned = true;
}

// Execute method - handles validation, then calls concrete implementation
void AForm::execute(Bureaucrat const & executor) const {
    // Check if form is signed
    if (!isSigned) {
        throw FormGradeTooLowException();
    }
    // Check if executor has sufficient grade
    if (executor.getGrade() > gradeToExecute) {
        throw FormGradeTooLowException();
    }
    // If all checks pass, call the concrete implementation
    executeAction();
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

// Output operator
std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out	<< "FormName: " << f.getName()
		<< ", FormIsSigned: " << f.getIsSigned()
		<< ", FormSignGrade: " << f.getGradeToSign()
		<< ", FormExecuteGrade: " << f.getGradeToExecute() << std::endl;
	return (out);
}
