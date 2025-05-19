/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:05:09 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:05:09 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string type) : type(type) {} 

void Weapon::setType(std::string new_type)
{
    type = new_type;
}
const std::string& Weapon::getType() const
{
    return type;
}