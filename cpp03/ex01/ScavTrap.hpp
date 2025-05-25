#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>
#include <string>


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		std::string setName();
		unsigned int setHit();
		unsigned int setattack();
		unsigned int setEnergy();
		void guardGate();
};

#endif