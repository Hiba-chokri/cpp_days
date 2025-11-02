#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << " TEST 1: Valid Form Creation ===" << std::endl;
    try {
        Form form1("Tax Return", 50, 25);
        std::cout << form1 << std::endl;
        
        Form form2("Building Permit", 100, 75);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // ========================================
    // TEST 2: Invalid Form Creation (Grades Too High)
    // ========================================
    std::cout << "\n=== TEST 2: Invalid Form Creation (Grades Too High) ===" << std::endl;
    try {
        Form invalidForm1("Top Secret", 0, 5); // gradeToSign = 0 (too high)
        std::cout << invalidForm1 << std::endl; // shouldn't print
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Classified", 10, 0); // gradeToExecute = 0 (too high)
        std::cout << invalidForm2 << std::endl; // shouldn't print
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // ========================================
    // TEST 3: Invalid Form Creation (Grades Too Low)
    // ========================================
    std::cout << "\n=== TEST 3: Invalid Form Creation (Grades Too Low) ===" << std::endl;
    try {
        Form invalidForm3("Simple Task", 151, 100); // gradeToSign = 151 (too low)
        std::cout << invalidForm3 << std::endl; // shouldn't print
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalidForm4("Easy Job", 100, 151); // gradeToExecute = 151 (too low)
        std::cout << invalidForm4 << std::endl; // shouldn't print
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // // ========================================
    // // TEST 4: Successful Form Signing
    // // ========================================
    std::cout << "\n=== TEST 4: Successful Form Signing ===" << std::endl;
    try {
        Form form("Driver's License", 80, 40);
        Bureaucrat clerk("Alice", 70); // Grade 70 can sign (70 <= 80)
        
        std::cout << "Before signing:" << std::endl;
        std::cout << form << std::endl;
        std::cout << clerk << std::endl;
        
        // Use Bureaucrat's signForm method
        clerk.signForm(form);
        
        std::cout << "After signing:" << std::endl;
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // // ========================================
    // TEST 5: Failed Form Signing (Grade Too Low)
    // ========================================
    std::cout << "\n=== TEST 5: Failed Form Signing (Grade Too Low) ===" << std::endl;
    try {
        Form form("Presidential Document", 10, 5);
        Bureaucrat intern("Bob", 50); // Grade 50 cannot sign (50 > 10)
        
        std::cout << "Before signing attempt:" << std::endl;
        std::cout << form << std::endl;
        std::cout << intern << std::endl;
        
        // This should fail and print error message
        intern.signForm(form);
        
        std::cout << "After signing attempt:" << std::endl;
        std::cout << form << std::endl; // Should still be unsigned
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // // ========================================
    // // TEST 6: Direct beSigned Method Testing
    // // ========================================
    // std::cout << "\n=== TEST 6: Direct beSigned Method Testing ===" << std::endl;
    // try {
    //     Form form("Test Form", 60, 30);
    //     Bureaucrat manager("Charlie", 40);
        
    //     std::cout << "Before beSigned:" << std::endl;
    //     std::cout << form << std::endl;
        
    //     form.beSigned(manager); // Should work (40 <= 60)
        
    //     std::cout << "After beSigned:" << std::endl;
    //     std::cout << form << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // // ========================================
    // // TEST 7: Direct beSigned Method Failure
    // // ========================================
    // std::cout << "\n=== TEST 7: Direct beSigned Method Failure ===" << std::endl;
    // try {
    //     Form form("High Security Form", 20, 10);
    //     Bureaucrat junior("Diana", 30); // Grade 30 cannot sign (30 > 20)
        
    //     std::cout << "Before beSigned attempt:" << std::endl;
    //     std::cout << form << std::endl;
        
    //     form.beSigned(junior); // Should throw exception
        
    //     std::cout << "After beSigned (shouldn't print):" << std::endl;
    //     std::cout << form << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // // ========================================
    // // TEST 8: Copy Constructor and Assignment
    // // ========================================
    // std::cout << "\n=== TEST 8: Copy Constructor and Assignment ===" << std::endl;
    // try {
    //     Form original("Original Form", 90, 60);
    //     Bureaucrat signer("Eve", 80);
        
    //     // Sign the original
    //     original.beSigned(signer);
        
    //     // Test copy constructor
    //     Form copy(original);
        
    //     // Test assignment operator
    //     Form assigned("Temp Form", 150, 150);
    //     assigned = original;
        
    //     std::cout << "Original: " << original << std::endl;
    //     std::cout << "Copy: " << copy << std::endl;
    //     std::cout << "Assigned: " << assigned << std::endl;
    // }
    // catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // // ========================================
    // // TEST 9: Multiple Bureaucrats, Multiple Forms
    // // ========================================
    // std::cout << "\n=== TEST 9: Multiple Bureaucrats, Multiple Forms ===" << std::endl;
    // try {
    //     // Create different bureaucrats with different authority levels
    //     Bureaucrat ceo("CEO", 1);           // Highest authority
    //     Bureaucrat manager("Manager", 25);  // High authority
    //     Bureaucrat employee("Employee", 75); // Medium authority
    //     Bureaucrat intern("Intern", 140);    // Low authority
        
    //     // Create forms with different requirements
    //     Form vipForm("VIP Document", 5, 3);      // Only CEO can sign/execute
    //     Form managerForm("Management Report", 30, 20); // Manager+ can sign
    //     Form employeeForm("Work Order", 80, 60);  // Employee+ can sign
    //     Form internForm("Copy Request", 150, 150); // Anyone can sign
        
    //     std::cout << "\n--- Bureaucrats ---" << std::endl;
    //     std::cout << ceo << std::endl;
    //     std::cout << manager << std::endl;
    //     std::cout << employee << std::endl;
    //     std::cout << intern << std::endl;
        
    //     std::cout << "\n--- Forms ---" << std::endl;
    //     std::cout << vipForm << std::endl;
    //     std::cout << managerForm << std::endl;
    //     std::cout << employeeForm << std::endl;
    //     std::cout << internForm << std::endl;
        
    //     std::cout << "\n--- Signing Attempts ---" << std::endl;
    //     // These should succeed
    //     ceo.signForm(vipForm);
    //     manager.signForm(managerForm);
    //     employee.signForm(employeeForm);
    //     intern.signForm(internForm);
        
    //     // These should fail
    //     intern.signForm(vipForm);      // Intern can't sign VIP document
    //     employee.signForm(managerForm); // Employee can't sign manager document
        
    // }
    // catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    std::cout << "\n========================================" << std::endl;
    std::cout << "            END OF TESTS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}
