#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    // Animal::operator=(other);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*other.brain);
    type = other.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}