#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void printSeparator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int main() {
    
    // ============================================
    // TEST 1: Basic Intern Form Creation
    // ============================================
    printSeparator("TEST 1: Intern Creates Valid Forms");
    
    try {
        Intern someRandomIntern;
        AForm* form1;
        AForm* form2;
        AForm* form3;
        
        // Create shrubbery form
        form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        std::cout << *form1 << std::endl;
        delete form1;
        
        std::cout << std::endl;
        
        // Create robotomy form
        form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form2 << std::endl;
        delete form2;
        
        std::cout << std::endl;
        
        // Create presidential pardon form
        form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *form3 << std::endl;
        delete form3;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 2: Invalid Form Name
    // // ============================================
    printSeparator("TEST 2: Invalid Form Name");
    
    try {
        Intern intern;
        AForm* form;
        
        // Try to create non-existent form
        form = intern.makeForm("coffee making request", "office");
        
        // This should not execute if exception is thrown
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 3: Case Sensitivity Test
    // // ============================================
    printSeparator("TEST 3: Case Variations");
    
    try {
        Intern intern;
        
        // Test different case variations
        std::cout << "Testing: 'Shrubbery Creation'" << std::endl;
        AForm* form1 = intern.makeForm("Shrubbery Creation", "garden");
        delete form1;
        
        std::cout << "\nTesting: 'ROBOTOMY REQUEST'" << std::endl;
        AForm* form2 = intern.makeForm("ROBOTOMY REQUEST", "target");
        delete form2;
        
        std::cout << "\nTesting: 'Presidential Pardon'" << std::endl;
        AForm* form3 = intern.makeForm("Presidential Pardon", "prisoner");
        delete form3;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 4: Complete Workflow (Create, Sign, Execute)
    // // ============================================
    printSeparator("TEST 4: Complete Workflow with Intern");
    
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        // Intern creates the form
        AForm* rrf = intern.makeForm("robotomy request", "Bender");
        
        std::cout << *rrf << std::endl;
        
        // Bureaucrat signs it
        boss.signForm(*rrf);
        
        std::cout << *rrf << std::endl;
        
        // Bureaucrat executes it
        boss.executeForm(*rrf);
        
        delete rrf;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 5: Multiple Interns, Multiple Forms
    // // ============================================
    printSeparator("TEST 5: Multiple Interns");
    
    try {
        Intern intern1;
        Intern intern2;
        Intern intern3;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "office");
        AForm* form2 = intern2.makeForm("robotomy request", "Employee_001");
        AForm* form3 = intern3.makeForm("presidential pardon", "Criminal_042");
        
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;
        
        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 6: Example from Subject
    // // ============================================
    printSeparator("TEST 6: Example from Subject");
    
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }

    // // ============================================
    // // TEST 7: Array of Different Form Names
    // // ============================================
    printSeparator("TEST 7: Batch Form Creation");
    
    try {
        Intern intern;
        std::string formNames[] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon",
            "invalid form name",
            "another invalid"
        };
        std::string targets[] = {
            "target1",
            "target2",
            "target3",
            "target4",
            "target5"
        };
        
        for (int i = 0; i < 5; i++) {
            std::cout << "\nAttempting to create: " << formNames[i] << std::endl;
            try {
                AForm* form = intern.makeForm(formNames[i], targets[i]);
                if (form) {
                    std::cout << *form << std::endl;
                    delete form;
                }
            }
            catch (std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 8: Full Process with All Form Types
    // // ============================================
    printSeparator("TEST 8: Complete Process - All Forms");
    
    try {
        Intern intern;
        Bureaucrat ceo("CEO", 1);
        Bureaucrat manager("Manager", 50);
        
        // Create all three types
        AForm* shrub = intern.makeForm("shrubbery creation", "headquarters");
        AForm* robot = intern.makeForm("robotomy request", "Defective_Unit");
        AForm* pardon = intern.makeForm("presidential pardon", "Tax_Evader");
        
        std::cout << "\n--- Forms Created ---" << std::endl;
        std::cout << *shrub << std::endl;
        std::cout << *robot << std::endl;
        std::cout << *pardon << std::endl;
        
        std::cout << "\n--- Signing Forms ---" << std::endl;
        ceo.signForm(*shrub);
        ceo.signForm(*robot);
        ceo.signForm(*pardon);
        
        std::cout << "\n--- Executing Forms ---" << std::endl;
        ceo.executeForm(*shrub);
        ceo.executeForm(*robot);
        ceo.executeForm(*pardon);
        
        std::cout << "\n--- Manager tries to execute (should fail some) ---" << std::endl;
         manager.executeForm(*pardon);  // Should fail - needs grade 5
        
        delete shrub;
        delete robot;
        delete pardon;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // // ============================================
    // // TEST 9: Empty String and Edge Cases
    // // ============================================
    printSeparator("TEST 9: Edge Cases");
    
    try {
        Intern intern;
        
        std::cout << "Testing empty form name:" << std::endl;
        AForm* form1 = intern.makeForm("", "target");
        delete form1;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Intern intern;
        
        std::cout << "\nTesting with whitespace:" << std::endl;
        AForm* form2 = intern.makeForm("   shrubbery creation   ", "target");
        if (form2) {
            std::cout << *form2 << std::endl;
            delete form2;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    
    return 0;
}