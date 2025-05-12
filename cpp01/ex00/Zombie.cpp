/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:04:21 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:04:21 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << name << " is deleted" << std::endl;
    
}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}