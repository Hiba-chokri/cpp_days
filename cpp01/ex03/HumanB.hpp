#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

class Weapon;

class HumanB {

    private :
     std::string name;
     Weapon *weapon;
    public :
        HumanB() {};
        HumanB(std::string name);
        void attack(void);
        void setWeapon(Weapon &weapon);
};

#endif