/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 14:04:31 by hichokri          #+#    #+#             */
/*   Updated: 2025-05-12 14:04:31 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	nbr = 4;
	std::string	zombieName = "Wolfie";

	Zombie	*zombies = zombieHorde(nbr, zombieName);


	for (int i = 0; i < nbr; i++)
		zombies[i].announce();

	delete[] zombies;

	return (0);
}