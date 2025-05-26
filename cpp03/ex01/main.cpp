#include "ScavTrap.hpp"



int main()
{
    ClapTrap obj("Aliens");
    ScavTrap obj2;
    ScavTrap obj1("fishie");
    
    unsigned int amount = 0;
    const std::string target = "army";
    
    obj.attack(target);
    obj.takeDamage(5);
    obj.beRepaired(1);
    obj.takeDamage(5);
    obj1.guardGate();

   obj2.attack(target);
   obj2.takeDamage(amount);
   obj2.beRepaired(amount);
    
}