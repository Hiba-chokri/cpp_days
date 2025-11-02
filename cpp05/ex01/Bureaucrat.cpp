#include "Bureaucrat.hpp"
#include "Form.hpp"

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
            return "Grade too low!";
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat constructed !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade): name(Name)
{
    if (Grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (Grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
   }
   grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    *this = obj;
    std::cout<<"copy constructor called "<<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
    {
        this->grade = obj.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructed !" << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out <<b.getName()<<", bureaucrat grade "<<b.getGrade();
    return out;
}

void Bureaucrat::incrementGrade()
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
   if (grade > 150)
   {
        throw GradeTooLowException();
   }
   grade++;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}