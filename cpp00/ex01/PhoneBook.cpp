/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:05:56 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:05:56 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
    countContact = 0;
}


int PhoneBook::getContactCount()  {
    return countContact;
}

std::string Contact::getFirstName() 
{ 
    return first_name; 
}

std::string Contact::getLastName() 
{ 
    return last_name;
}
std::string Contact::getNickName() 
{ 
    return nickname; 
}
std::string Contact::getPhoneNumber() 
{ 
    return phone_number; 
}
std::string Contact::getDarkestSecret() 
{ 
    return darkest_secret; 
}