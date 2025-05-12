#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        zombie(std::string name);
        ~zombie(void);
        void announce(void);
}

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif