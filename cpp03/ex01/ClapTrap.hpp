#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <iostream>
#include <string>
#include <cstdlib>


class ClapTrap 
{
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &other);
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif