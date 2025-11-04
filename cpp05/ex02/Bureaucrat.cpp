#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat constructed !" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade): name(Name)
{
    if (Grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (Grade > 150)
   {
        throw GradeTooLowException();
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
            return "Grade too low!";
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

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);  // Call AForm's beSigned method
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);  // Call AForm's execute method
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}