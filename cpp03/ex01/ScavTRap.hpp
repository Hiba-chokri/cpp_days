#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>
#include <string>


class ScavTrap : public ClapTrap
{
	private:
	 std::string n;
		unsigned int htPoints;
		unsigned int attDamage;
		unsigned int enPoints;
	public:
		ScavTrap();
		ScavTrap(const std::string& n);
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