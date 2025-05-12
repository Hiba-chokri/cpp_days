/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:05:40 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:05:40 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// function to count the number of caracters in a string
int count_characters(std::string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

void Contact::set_first_name()
{
        std::string input;
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        while (input.empty()) {
            std::cout << "Field cannot be empty. Try again: ";
            std::getline(std::cin, input);
        }
        if(count_characters(input) > 10)
        {
            // if it has more than 10 characters substring it to 9
            input = input.substr(0, 9);
            // add a dot at the end
            input += ".";
            this->first_name = input;
            std::cout << "First name is too long. It should be less than 10 characters." << std::endl;
        }
        else
            this->first_name = input;

}
void Contact::set_last_name()
{
    std::string input;

        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        while (input.empty()) {
            std::cout << "Field cannot be empty. Try again: ";
            std::getline(std::cin, input);
        }
        if(count_characters(input) > 10)
        {
            // if it has more than 10 characters substring it to 9
            input = input.substr(0, 9);
            // add a dot at the end
            input += ".";
            this->last_name = input;
            std::cout << "Last name is too long. It should be less than 10 characters." << std::endl;
        }
        else
            this->last_name = input;
}
void Contact::set_nickname()
{
    std::string input;

        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        while (input.empty()) {
            std::cout << "Field cannot be empty. Try again: ";
            std::getline(std::cin, input);
        }
        if(count_characters(input) > 10)
        {
            // if it has more than 10 characters substring it to 9
            input = input.substr(0, 9);
            // add a dot at the end
            input += ".";
            this->nickname = input;
            std::cout << "Nickname is too long. It should be less than 10 characters." << std::endl;
        }
        else
            this->nickname = input;
}
void Contact::set_phone_number()
{
    std::string input;

        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        while (input.empty()) {
            std::cout << "Field cannot be empty. Try again: ";
            std::getline(std::cin, input);
        }
        if(count_characters(input) > 10)
        {
            // if it has more than 10 characters substring it to 9
            input = input.substr(0, 9);
            // add a dot at the end
            input += ".";
            this->phone_number = input;
            std::cout << "Phone number is too long. It should be less than 10 characters." << std::endl;
        }
        else
            this->phone_number = input;
}

void Contact::set_darkest_secret()
{
    std::string input;

        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        while (input.empty()) {
            std::cout << "Field cannot be empty. Try again: ";
            std::getline(std::cin, input);
        }
        if(count_characters(input) > 10)
        {
            // if it has more than 10 characters substring it to 9
            input = input.substr(0, 9);
            // add a dot at the end
            input += ".";
            this->darkest_secret = input;
            std::cout << "Darkest secret is too long. It should be less than 10 characters." << std::endl;
        }
        else
            this->darkest_secret = input;
}

void Contact::create_contact()
{
    set_first_name();
    set_last_name();
    set_nickname();
    set_phone_number();
    set_darkest_secret();
}

void PhoneBook::add_contact()
{
    if (index >= 8)
    {
       index = index % 8;
       contacts[index].create_contact();
    }
    else
        contacts[index].create_contact();
    index++;
}
// create a function to display the contact

void Contact::print_contact()
{
    std::cout << "First Name: " << getFirstName() << " | " << std::cout << "Last Name: " << getLastName() << " | " << std::cout << "Nickname: " << getNickName() << std::endl;
}
void PhoneBook::search_contact()
{
    std::string input;
    std::cout << "Enter the index of the contact you want to search: ";
    std::getline(std::cin, input);
    int index = atoi(input.c_str());
    if(this->index == 0)
    {
        std::cout << "No contacts found. Please add a contact first." << std::endl;
        return ;
    }
    else if (index < 0 || index >= 8)
        std::cout << "enter a valid index of the entry" << std::endl;
    else
        contacts[index].print_contact();
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
    PhoneBook phonebook;
    (void)argc;
    (void)argv;

    while(1)
    {
        print_menu();
        std::cout << "Please enter a command : "<< std::endl;
        getline(std::cin, command);
        if (command.compare("ADD") == 0)
            phonebook.add_contact();
        else if (command.compare("SEARCH") == 0)
            phonebook.search_contact();
        else if (command.compare("EXIT") == 0)
        {
            std::cout << "Exiting" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
}