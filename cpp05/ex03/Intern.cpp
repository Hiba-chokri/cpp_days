#include "Intern.hpp"
#include "AForm.hpp"
Intern::Intern()
{
    std::cout << "Intern Constructed !" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
    (void)obj;
    return *this;
}

AForm* Intern::makeForm(std::string FormName, std::string targetForm)
{
    std::string arr[3] = {"robotomy request" , "shrubbery creation", "presidential pardon" };
    int j = -1;

    for(int i = 0; i < 3; i++)
    {
        if (arr[i] == FormName)
        {
            j = i;
            std::cout << "Intern creates " << FormName << std::endl; 
            break;
        }
    }
    switch (j) 
    {
        case(0):
            return new RobotomyRequestForm(targetForm);
        case(1):
            return new ShrubberyCreationForm(targetForm);
        case(2):
            return new PresidentialPardonForm(targetForm);
        default:
            std::cout << "Intern couldn't find the form: " << FormName << std::endl;
    }
    return NULL;
}

Intern::~Intern()
{
    std::cout << "Intern denstructed !" << std::endl;
}
