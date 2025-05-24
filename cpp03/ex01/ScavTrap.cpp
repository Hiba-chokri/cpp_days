#include "ScavTRap.hpp"

using std::cout;

ScavTrap::ScavTrap() {
  std::cout << "Default constructor called\n" << std::endl;
}

ScavTrap::ScavTrap(const std::string& n)
{
  cout << "ScavTRap Constructor called for" << std::endl;
 }

ScavTrap::ScavTrap(const ScavTrap& other) {
	*this = other;
	std::cout << "ScavTrap " << n << " copy-constructed"<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		n = other.n;
		htPoints = other.htPoints;
		enPoints = other.enPoints;
		attDamage = other.attDamage;
	}
	std::cout << "ScavTrap " << n << " assigned"<<std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << n << " destroyed"<<std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << n << " is now in Gate Keeper mode"<<std::endl;
}