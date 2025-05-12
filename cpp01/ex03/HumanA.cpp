/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:04:58 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:04:58 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::name, Weapon& weapon)
{
    this->name = name;
    this->weapon = weapon;
}

void HumanA::attack(void)
{
    std::cout<<name << "attacks with their "<< getType()<<std::endl;
}