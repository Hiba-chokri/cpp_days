#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;  // Forward declaration

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string Name, int Grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form) const;
        void executeForm(AForm const & form) const;
        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();  // overrides std::exception::what()
        };
        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };       
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif