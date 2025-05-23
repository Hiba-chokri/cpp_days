#include "Fixed.hpp"

float Fixed::toFloat() const {
    return (float)this->fixed_point / (1 << fraction); // fraction = 8, shift left
}

int Fixed::toInt() const {
    return this->fixed_point >> fraction;  // shift right by 8 bits
}

std::ostream& operator<<(std::ostream& out, const Fixed& value){
    out << value.toFloat();
    return out;
}