/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 16:46:34 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 16:46:34 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info(void)
{
    std::cout<<"I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!"<<std::endl;
}

void Harl::warning(void)
{
    std::cout<<"I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error(void)
{
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
    typedef void (Harl::*ptr_member)();
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    ptr_member commands[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i=0; i<4 ;i++)
    {
        if (level == levels[i])
        {
            (this->*commands[i])();
            break;
        }
    }
}