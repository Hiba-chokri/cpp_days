#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

#include<iostream>
#include<string>
#include <cstdlib> 
#include <bits/stdc++.h>
#include <iomanip>
#include<cstring>

class Contact{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    public:
        Contact();
        void create_contact();
        void set_first_name();
        void set_last_name();
        void set_nickname();
        void set_phone_number();
        void set_darkest_secret();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        void print_contact(int index);
        void display_contact(int index);
};

class PhoneBook {
    private:
    Contact contacts[8];
    int index;
    int countContact;
    public:
        PhoneBook();
        int getContactCount() ;
        void add_contact();
        void search_contact();
        
};

# endif