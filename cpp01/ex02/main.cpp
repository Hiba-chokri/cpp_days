/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:04:50 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:04:50 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>


int main(void)
{
    std::string sentence = "HI THIS IS BRAIN";
    std::string *stringPtr = &sentence;
    std::string &stringRef = sentence;

    std::cout << "Address of string: " << &sentence << std::endl;
    std::cout << "Address of string pointer: " << stringPtr << std::endl;
    std::cout << "Address of string reference: " << &stringRef << std::endl;

    std::cout << "Value of string: " << sentence << std::endl;
    std::cout << "Value of string pointer: " << *stringPtr << std::endl;
    std::cout << "Value of string reference: " << stringRef << std::endl;
}