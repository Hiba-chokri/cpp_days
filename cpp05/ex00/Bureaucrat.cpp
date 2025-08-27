#include "Bureaucrat.hpp"

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
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
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

class GradeTooHighException: public std::exception {
    public:
        const char* what() const throw() {
            return "Grade too high!";
        }
};

class GradeTooLowException: public std::exception {
    public:
        const char* what() const throw() {
            return "Grade too low!";
        }
};

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