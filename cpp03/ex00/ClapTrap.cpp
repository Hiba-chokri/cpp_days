#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constractor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}
void ClapTrap::attack(const std::string &target)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else
        std::cout << name << " has no energy or hit points left to attack!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        hitPoints -= amount;
        std::cout << name << " takes " << amount << " points of damage!\n";
        if (hitPoints <= 0)
            std::cout << name << " has been destroyed!\n";
    }
    else
        std::cout << name << " is already destroyed!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << name << " repairs itself for " << amount << " hit points!\n";
    }
    else
        std::cout << name << " has no energy or hit points left to repair!\n";
}