#include "ScavTRap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called\n"<< std::endl;
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(name)
{
    std::cout << "ScavTRap Constructor called for"<< std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	*this = other;
	std::cout << "ScavTrap " << name << " copy-constructed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ScavTrap " << name << " assigned\n";
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode\n";
}