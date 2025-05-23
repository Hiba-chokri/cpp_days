#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <stdlib.h>

class Fixed {
    private :
        int fixed_point;
        static const int fraction = 8;
    public :
        Fixed()
        {
            fixed_point = 0;
            std::cout<<"Default constructor called"<<std::endl;
        }
        ~Fixed ()
        {
            std::cout<<"Destructor called"<<std::endl;
        }
        Fixed (const Fixed &obj)
        {
            std::cout<<"Copy constructor called"<<std::endl;
            this->fixed_point = obj.fixed_point;
        }
        Fixed& operator=(const Fixed& other)
        {
            std::cout<<"Copy assignment operator called"<<std::endl;
            if (this != &other)
            {
                this->fixed_point = other.fixed_point;
            }
            return (*this);
        }
        Fixed(const int nbr)
        {
            this->fixed_point = nbr << this->fraction;
        }
        Fixed(float const value) {
            this->fixed_point = roundf(value * (1 << 8));
        }
        bool operator>(const Fixed &val) const;
        bool operator<(const Fixed &val) const;
        bool operator>=(const Fixed &val) const;
        bool operator<=(const Fixed &val) const;
        bool operator==(const Fixed &val) const;
        bool operator!=(const Fixed &val) const;
        Fixed operator+(const Fixed &val) const;
        Fixed operator-(const Fixed &val) const;
        Fixed operator*(const Fixed &val) const;
        Fixed operator/(const Fixed &val) const;
        Fixed operator++(int);
        float toFloat( void ) const;
        int toInt( void ) const;
};

#endif