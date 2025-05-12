#ifndef HUMAN_B_H
#define HUMAN_B_H

class HumanB {

    private :
     std::string name;
     Weapon *weapon;
    public :
        HumanB(std::string name);
        void attack(void);
        void setWeapon(Weapon *weapon);
}