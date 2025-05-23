#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
        int getRawBits() const ;
        void setRawBits( int const raw );
};

#endif