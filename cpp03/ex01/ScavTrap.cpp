#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
  std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parametrized Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << name << " copy constructed called"<<std::endl;
	
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout<<"Scavtrap copy assignement operetor called"<<std::endl;
        ClapTrap::operator=(other);
    return *this;
}


void ScavTrap::attack(const std::string &target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"<<std::endl;
        energyPoints--;
    }
    else
        std::cout << name << " has no energy or hit points left to attack!"<<std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed"<<std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode"<<std::endl;
}
