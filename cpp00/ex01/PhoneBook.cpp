3include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0; // initialize index when the phonebook is created
}

Contact::Contact() {
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

void getFirstName