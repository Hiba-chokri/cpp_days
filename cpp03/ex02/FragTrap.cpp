#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
    std::cout << "FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    std::cout << "FragTrap copy assignment operator called"<<std::endl;
    ClapTrap::operator=(other);
    return *this;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called"<<std::endl;
}
void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap " << name << " is requesting a high five!"<< std::endl;
}