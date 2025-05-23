#include "Fixed.hpp"


int main( void ) {
    Fixed a;// we created an object of class Fixed
    Fixed b( a ); // creating a copy constructor of object a
    Fixed c; // copy assignement operator
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}