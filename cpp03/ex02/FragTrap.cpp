#include "FragTrap.hpp"

FragTrap::FragTrap() : ScavTrap() {
    std::cout << "Default FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(const std::string& name) : ScavTrap(name) {
    hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
    std::cout << "FragTrap constructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ScavTrap(other) {
    std::cout << "FragTrap copy constructor called"<<std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called"<<std::endl;
    if (this != &other) {
        ScavTrap::operator=(other);
    }
    return *this;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called"<<std::endl;
}
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " is requesting a high five!"<< std::endl;
}