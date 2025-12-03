#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <list>
#include <iostream>
#include <stdexcept>


template<typename T>
typename T::iterator easyfind(T& container , int value)
{
    
    typename T::iterator it = std::find(container.begin(), it != container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}


#endif