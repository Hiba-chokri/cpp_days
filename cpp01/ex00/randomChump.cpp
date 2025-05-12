/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:04:14 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:04:14 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	randomZombie(name);

	randomZombie.announce();
}