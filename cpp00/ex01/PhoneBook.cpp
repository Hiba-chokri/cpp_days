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