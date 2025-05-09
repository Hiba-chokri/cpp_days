#include "PhoneBook.hpp"

void exit_program()
{
    exit(1);
}



void print_menu()
{
    std::cout << "1. to add a contact enter : ADD" << std::endl;
    std::cout << "2. to Search a contact enter : SEARCH" << std::endl;
    std::cout << "3.to exit enter : EXIT" << std::endl;
}
int main(int argc, char **argv)
{
    std::string command;
    (void)argc;
    (void)argv;
    while(1)
    {
        print_menu();
        std::cout << "Please enter a command : "<< std::endl;
        getline(std::cin, command);
        if (command.compare("EXIT"))
            exit_program();

    }
}