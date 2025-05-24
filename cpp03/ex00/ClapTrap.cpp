#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called"<<std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Copy constructor called"<<std::endl;
    this->name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called"<<std::endl;
    *this = other;
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called"<<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called"<<std::endl;
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
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"<<std::endl;
        energyPoints--;
    }
    else
        std::cout << name << " has no energy or hit points left to attack!"<<std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        hitPoints -= amount;
        std::cout << name << " takes " << amount << " points of damage!"<<std::endl;
        if (hitPoints <= 0)
            std::cout << name << " has been destroyed!"<<std::endl;
    }
    else
        std::cout << name << " is already destroyed!"<<std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints > 0 && energyPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << name << " repairs itself for " << amount << " hit points!"<<std::endl;
    }
    else
        std::cout << name << " has no energy or hit points left to repair!"<<std::endl;
}