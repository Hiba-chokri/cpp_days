#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain default constructor is called"<<std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = "idea";
    }
}

Brain::Brain(const Brain& other)
{
    std::cout<<"brain copy constructor is called"<<std::endl;
    for (int i = 0; i < 100; ++i) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout<<"brain assignement operator is called"<<std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout<<"brain destructor is called"<<std::endl;
}
