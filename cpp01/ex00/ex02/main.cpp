#include<iostream>


int main(void)
{
    std::string sentence = "HI THIS IS BRAIN";
    std::stringPTR *stringPtr = &sentence;
    std::string &stringRef = sentence;

    std::cout << "Address of string: " << &sentence << std::endl;
    std::cout << "Address of string pointer: " << stringPtr << std::endl;
    std::cout << "Address of string reference: " << &stringRef << std::endl;

    std::cout << "Value of string: " << sentence << std::endl;
    std::cout << "Value of string pointer: " << *stringPtr << std::endl;
    std::cout << "Value of string reference: " << stringRef << std::endl;
}