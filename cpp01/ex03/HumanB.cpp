/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:05:01 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:05:01 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

void HumanB::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}


void HumanB::attack(void)
{
    std::cout<<this->name << "attacks with their "<< this->weapon->setWeapon<<std::endl;
}
