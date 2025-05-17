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
        bool allPrintable = true;
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        for (size_t i = 0; i < input.length(); ++i) {
            if (!isprint(static_cast<unsigned char>(input[i]))) {
                allPrintable = false;
                break;
            }
        }
        while (input.empty() || !allPrintable) {
            allPrintable = true;
                std::cout << "Field cannot be empty or contain non-printable characters."<<std::endl;
                std::cout << "Enter First Name: "<<std::endl;
                std::getline(std::cin, input);
                for (size_t i = 0; i < input.length(); ++i) {
                    if (!isprint(static_cast<unsigned char>(input[i]))) {
                        allPrintable = false;
                        break;
                    }
                }
        }
        if(count_characters(input) > 10)
        {
            input = input.substr(0, 9);
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
    bool allPrintable = true;
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        for (size_t i = 0; i < input.length(); ++i) {
            if (!isprint(static_cast<unsigned char>(input[i]))) {
                allPrintable = false;
                break;
            }
        }
        while (input.empty() || !allPrintable) {
            allPrintable = true;
                std::cout << "Field cannot be empty or contain non-printable characters."<<std::endl;
                std::cout << "Enter Last Name: "<<std::endl;
                std::getline(std::cin, input);
                for (size_t i = 0; i < input.length(); ++i) {
                    if (!isprint(static_cast<unsigned char>(input[i]))) {
                        allPrintable = false;
                        break;
                    }
                }
        }
        if(count_characters(input) > 10)
        {
            input = input.substr(0, 9);
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
    bool allPrintable = true;
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        for (size_t i = 0; i < input.length(); ++i) {
            if (!isprint(static_cast<unsigned char>(input[i]))) {
                allPrintable = false;
                break;
            }
        }
        while (input.empty() || !allPrintable) {
            allPrintable = true;
                std::cout << "Field cannot be empty or contain non-printable characters."<<std::endl;
                std::cout << "Enter Nickname: "<<std::endl;
                std::getline(std::cin, input);
                for (size_t i = 0; i < input.length(); ++i) {
                    if (!isprint(static_cast<unsigned char>(input[i]))) {
                        allPrintable = false;
                        break;
                    }
                }
        }
        if(count_characters(input) > 10)
        {
            input = input.substr(0, 9);
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
    bool allPrintable = true;
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        for (size_t i = 0; i < input.length(); ++i) {
            if (!isprint(static_cast<unsigned char>(input[i]))) {
                allPrintable = false;
                break;
            }
        }
        while (input.empty() || !allPrintable) {
            allPrintable = true;
                std::cout << "Field cannot be empty or contain non-printable characters."<<std::endl;
                std::cout << "Enter Phone Number: "<<std::endl;
                std::getline(std::cin, input);
                for (size_t i = 0; i < input.length(); ++i) {
                    if (!isprint(static_cast<unsigned char>(input[i]))) {
                        allPrintable = false;
                        break;
                    }
                }
        }
        if(count_characters(input) > 10)
        {
            input = input.substr(0, 9);
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
    bool allPrintable = true;
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        for (size_t i = 0; i < input.length(); ++i) {
            if (!isprint(static_cast<unsigned char>(input[i]))) {
                allPrintable = false;
                break;
            }
        }
        while (input.empty() || !allPrintable) {
            allPrintable = true;
                std::cout << "Field cannot be empty or contain non-printable characters."<<std::endl;
                std::cout << "Enter Darkest Secret: "<<std::endl;
                std::getline(std::cin, input);
                for (size_t i = 0; i < input.length(); ++i) {
                    if (!isprint(static_cast<unsigned char>(input[i]))) {
                        allPrintable = false;
                        break;
                    }
                }
        }
        if(count_characters(input) > 10)
        {
            input = input.substr(0, 9);
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
       index++;
    }
    else
    {
        contacts[index].create_contact();
        index++;
    }
    this->countContact++;
}

void Contact::print_contact(int index)
{
    std::cout<< std::setw(10)<< "Index" << "|"<< std::setw(10)<< "First Name" << "|"<< std::setw(10) << "Last Name" << "|" << std::setw(10) <<"Nickname" << "|"<< std::endl;
    std::cout << std::setw(10) << index <<"|"<< std::setw(10) << getFirstName() << "|"  << std::setw(10) << getLastName() << "|" << std::setw(10) << getNickName()<< "|" << std::endl;
}

void Contact::display_contact(int index)
{
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << getFirstName() << std::endl;
    std::cout << "Last Name: " << getLastName() << std::endl;
    std::cout << "Nickname: " << getNickName() << std::endl;
    std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

void PhoneBook::search_contact()
{
    for(int i=0 ; i < this->index; i++)
    {
                contacts[i].print_contact(i);
    }
    std::string input;
    std::cout << "Enter the index of the contact you want to search: ";
    std::getline(std::cin, input);
    bool is_digit = true;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            is_digit = false;
            break;
        }
    }
    if (is_digit)
    {
        int idx = std::atoi(input.c_str());
        if (this->index == 0)
        {
            std::cout << "No contacts found. Please add a contact first." << std::endl;
            return ;
        }
        else if (idx < 0 || idx > 7)
            std::cout << "Enter a valid index between 0 and 7." << std::endl;
        else if (idx >= this->countContact )
            std::cout << "Index out of range." << std::endl;
        else
        {
            for(int i=0; i< this->index; i++)
            {
                if (i== idx)
                    contacts[i].display_contact(idx);
            }
        }
    }
    else
        std::cout << "Invalid input. Please enter a number between 0 and 7." << std::endl;
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
        if (!getline(std::cin, command))
            break;
        else{
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
}