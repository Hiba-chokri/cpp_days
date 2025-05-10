#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

#include<iostream>
#include<string>
#include <cstdlib> 
#include <bits/stdc++.h>

class Contact{
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    public:
        Contact(){};
        void create_contact();
        void set_first_name();
        void set_last_name();
        void set_nickname();
        void set_phone_number();
        void set_darkest_secret();
        std::string getFirstName() { return first_name; }
        std::string getLastName() { return last_name; }
        std::string getNickName() { return nickname; }
        void print_contact();
        void display_contact();
};

class PhoneBook {
    private:
    Contact contacts[8];
    int index;
    public:
        PhoneBook(){};
        void add_contact();
        void search_contact();
};

# endif