#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
{
    type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    Animal::operator=(other);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*other.brain);
    type = other.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}
void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}