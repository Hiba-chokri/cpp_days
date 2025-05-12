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