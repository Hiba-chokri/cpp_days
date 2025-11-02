#include "AForm.hpp"

const char	*AForm::FormGradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char	*AForm::FormGradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form::FormNotSignedException");
}

const char	*AForm::FormFileException::what() const throw()
{
	return ("Form::FormFileException: File could not be opened.");
}

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw FormGradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw FormGradeTooLowException();
    }
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm& obj) 
    : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& obj) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &obj) {
        isSigned = obj.isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

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

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign) {
        throw FormGradeTooLowException();
    }
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out	<< "FormName: " << f.getName()
		<< ", FormIsSigned: " << f.getIsSigned()
		<< ", FormSignGrade: " << f.getGradeToSign()
		<< ", FormExecuteGrade: " << f.getGradeToExecute() << std::endl;
	return (out);
}

