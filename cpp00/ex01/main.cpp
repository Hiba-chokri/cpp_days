#include "PhoneBook.hpp"

void print_menu()
{
    std::cout << "1. to add a contact enter : ADD" << std::endl;
    std::cout << "2. to Search a contact enter : SEARCH" << std::endl;
    std::cout << "3.to exit enter : EXIT" << std::endl;
}
int main(int argc, char **argv)
{
    print_menu();
    return (0);
}