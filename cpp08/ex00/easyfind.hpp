#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <list>
#include <iostream>
#include <stdexcept>


template<typename T>
typename T::iterator easyfind(T& container , int value)
{
    for(typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == value)
        {
            return it;
        }
    }
    throw std::runtime_error("Value not found");
}


#endif