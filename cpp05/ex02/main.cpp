#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printSeparator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int main() {
    
    // ============================================
    // TEST 1: Basic Form Creation and Info Display
    // ============================================
    printSeparator("TEST 1: Create Forms");
    
    try {
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 2: Try to Execute Unsigned Form
    // ============================================
    printSeparator("TEST 2: Execute Unsigned Form (should fail)");
    
    try {
        ShrubberyCreationForm shrub("garden");
        Bureaucrat boss("Boss", 1);
        
        std::cout << "Trying to execute unsigned form..." << std::endl;
        boss.executeForm(shrub);  // Should fail - not signed yet
    }
    catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 3: Sign and Execute ShrubberyCreationForm
    // ============================================
    printSeparator("TEST 3: ShrubberyCreationForm - Success");
    
    try {
        ShrubberyCreationForm shrub("office");
        Bureaucrat bob("Bob", 130);  // Grade 130: can sign (145) and exec (137)
        
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        std::cout << shrub << std::endl;
        bob.executeForm(shrub);
        std::cout << "Check for 'office_shrubbery' file in your directory!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 4: Grade Too Low to Sign
    // ============================================
    printSeparator("TEST 4: Grade Too Low to Sign");
    
    try {
        RobotomyRequestForm robot("R2D2");
        Bureaucrat intern("Intern", 100);  // Grade 100: too low to sign (needs 72)
        
        std::cout << robot << std::endl;
        intern.signForm(robot);  // Should fail
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 5: Grade Too Low to Execute
    // ============================================
    printSeparator("TEST 5: Grade Too Low to Execute");
    
    try {
        RobotomyRequestForm robot("C3PO");
        Bureaucrat manager("Manager", 50);   // Can sign (72) but can't exec (45)
        Bureaucrat lowLevel("LowLevel", 70); // Can sign (72)
        
        std::cout << robot << std::endl;
        lowLevel.signForm(robot);  // Success
        std::cout << robot << std::endl;
        manager.executeForm(robot);  // Should fail - grade 50 too low for exec (needs 45)
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 6: RobotomyRequestForm - Success (50% chance)
    // ============================================
    printSeparator("TEST 6: RobotomyRequestForm - Success");
    
    try {
        RobotomyRequestForm robot1("Bender");
        RobotomyRequestForm robot2("Marvin");
        RobotomyRequestForm robot3("Wall-E");
        Bureaucrat boss("Boss", 1);
        
        // Try multiple times to see random 50% success/fail
        boss.signForm(robot1);
        boss.executeForm(robot1);
        
        std::cout << std::endl;
        boss.signForm(robot2);
        boss.executeForm(robot2);
        
        std::cout << std::endl;
        boss.signForm(robot3);
        boss.executeForm(robot3);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 7: PresidentialPardonForm - Success
    // ============================================
    printSeparator("TEST 7: PresidentialPardonForm - Success");
    
    try {
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat president("President", 1);  // Grade 1: can do anything
        
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        std::cout << pardon << std::endl;
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 8: PresidentialPardonForm - Fail (grade too low)
    // ============================================
    printSeparator("TEST 8: PresidentialPardonForm - Fail");
    
    try {
        PresidentialPardonForm pardon("Zaphod");
        Bureaucrat vicePresident("VP", 10);  // Grade 10: can sign (25) but can't exec (5)
        
        vicePresident.signForm(pardon);  // Success
        vicePresident.executeForm(pardon);  // Fail
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 9: Multiple Forms with Same Bureaucrat
    // ============================================
    printSeparator("TEST 9: One Bureaucrat, Multiple Forms");
    
    try {
        Bureaucrat superBoss("SuperBoss", 1);
        
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("Data");
        PresidentialPardonForm pardon("Trillian");
        
        // Sign all
        superBoss.signForm(shrub);
        superBoss.signForm(robot);
        superBoss.signForm(pardon);
        
        std::cout << std::endl;
        
        // Execute all
        superBoss.executeForm(shrub);
        superBoss.executeForm(robot);
        superBoss.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 10: Edge Cases - Exact Grade Requirements
    // ============================================
    printSeparator("TEST 10: Edge Cases - Exact Grades");
    
    try {
        ShrubberyCreationForm shrub("boundary");
        Bureaucrat exactSign("ExactSign", 145);    // Exactly the sign requirement
        Bureaucrat exactExec("ExactExec", 137);    // Exactly the exec requirement
        
        std::cout << "Testing exact grade boundaries..." << std::endl;
        exactSign.signForm(shrub);    // Should succeed
        exactExec.executeForm(shrub);  // Should succeed
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // ============================================
    // TEST 11: Copy Forms (if you implemented OCF properly)
    // ============================================
    printSeparator("TEST 11: Orthodox Canonical Form Test");
    
    try {
        ShrubberyCreationForm original("original");
        Bureaucrat signer("Signer", 100);
        
        signer.signForm(original);
        
        // Copy constructor
        ShrubberyCreationForm copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    printSeparator("END OF TESTS");
    
    return 0;
}