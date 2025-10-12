#include "Form.hpp"

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

Form::~Form() {
    std::cout << "Form destructed !" << std::endl;
}

Form::Form(): name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form constructed !" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150)
   {
        throw GradeTooLowException();
   }
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}
