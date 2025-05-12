#include "zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << name << " is deleted" << std::endl;
    
}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}