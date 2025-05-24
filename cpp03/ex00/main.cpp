#include "ClapTrap.hpp"

// std::ostream& operator<<(std::ostream& out, const ClapTrap& value){
//     out << value.toFloat();
//     return out;
// }

int main()
{
    ClapTrap obj("Aliens");
    ClapTrap obj2("Hero");

    unsigned int amount = 40;
    const std::string target = "army";
    obj.attack(target);
    obj.takeDamage(amount);
    obj.beRepaired(amount);

   obj2.attack(target);
   obj2.takeDamage(amount);
   obj2.beRepaired(amount);
   obj2 = obj;
    
}