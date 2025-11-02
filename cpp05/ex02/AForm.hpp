#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"




class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& obj);
        AForm& operator=(const AForm& obj);
        ~AForm();
        virtual void execute(Bureaucrat const & executor) const = 0;
        class FormGradeTooHighException : public std::exception
        {
        public:
            const char	*what() const throw();
        };

        class FormGradeTooLowException : public std::exception
        {
        public:
            const char	*what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
        public:
            const char	*what() const throw();
        };

        class FormFileException : public std::exception
        {
        public:
            const char	*what() const throw();
        };
        // getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif