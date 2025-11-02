#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm parameterized constructor called with target: " << target << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), target(obj.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &obj) {
        AForm::operator=(obj);
        target = obj.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // First, validate execution (handled by base class)
     if (!getIsSigned())
		throw (FormNotSignedException());
	if (executor.getGrade() > getGradeToExecute())
        throw FormGradeTooLowException();
// Execute action - creates file and writes ASCII trees (validation handled by base class)
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    file << "                                              ." << std::endl;
    file << "                                   .         ;  " << std::endl;
    file << "      .              .              ;%     ;;   " << std::endl;
    file << "        ,           ,                :;%  %;   " << std::endl;
    file << "         :         ;                   :;%;'     .,   " << std::endl;
    file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
    file << "             `@%.  `;@%.      ;@@%;         " << std::endl;
    file << "               `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                 ;@%. :@%%  %@@%;       " << std::endl;
    file << "                   %@bd%%%bd%%:;     " << std::endl;
    file << "                     #@%%%%%:;;" << std::endl;
    file << "                     %@@%%%::;" << std::endl;
    file << "                     %@@@%(o);  . '         " << std::endl;
    file << "                     %@@@o%;:(.,'         " << std::endl;
    file << "                 `.. %@@@o%::;         " << std::endl;
    file << "                    `)@@@o%::;         " << std::endl;
    file << "                     %@@(o)::;        " << std::endl;
    file << "                    .%@@@@%::;         " << std::endl;
    file << "                    ;%@@@@%::;.          " << std::endl;
    file << "                   ;%@@@@%%:;;;. " << std::endl;
    file << "               ...;%@@@@@%%:;;;;,..    " << std::endl;
    
    file.close();
    std::cout << "ShrubberyCreationForm executed successfully. File created: " << filename << std::endl;

}