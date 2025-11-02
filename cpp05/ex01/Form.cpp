#include "Form.hpp"

const char	*Form::FormGradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*Form::FormGradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}
std::string Form::getName() const {
    return name;
}
bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

Form::Form(): name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form constructed !" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw FormGradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150)
   {
        throw FormGradeTooLowException();
   }
}

Form::Form(const Form& obj) : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {
    std::cout << "Form copy constructor called!" << std::endl;
}

Form& Form::operator=(const Form& obj) {
    std::cout << "Form assignment operator called!" << std::endl;
    if (this != &obj) {
        // Note: name, gradeToSign, and gradeToExecute are const, so they can't be reassigned
        // Only isSigned can be copied
        isSigned = obj.isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructed !" << std::endl;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw FormGradeTooLowException();
    }
    isSigned = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	os	<< "FormName: " << other.getName()
		<< ", FormIsSigned: " << other.getIsSigned()
		<< ", FormSignGrade: " << other.getGradeToSign()
		<< ", FormExecuteGrade: " << other.getGradeToExecute() << std::endl;
	return (os);
}