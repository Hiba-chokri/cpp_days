#include "Fixed.hpp" 

bool Fixed::Fixed::operator>(const Fixed &val) const {
return this->fixed_point > val.fixed_point;
}

bool Fixed::operator<(const Fixed &val) const {
    return this->fixed_point > val.fixed_point;
}

bool Fixed::operator>=(const Fixed &val) const {
    return this->fixed_point > val.fixed_point;
}

bool Fixed::operator<=(const Fixed &val) const {
    return this->fixed_point > val.fixed_point;
}

bool Fixed::operator==(const Fixed &val) const {
    return this->fixed_point > val.fixed_point;
}

bool Fixed::operator!=(const Fixed &val) const {
    return this->fixed_point > val.fixed_point;
}

Fixed Fixed::operator+(const Fixed &val) const{
    Fixed result;
    result.fixed_point = this->fixed_point + val.fixed_point;
    return result;
}

Fixed Fixed::operator-(const Fixed &val) const{
    Fixed result;
    result.fixed_point = this->fixed_point - val.fixed_point;
    return result;
}

Fixed Fixed::operator*(const Fixed &val) const{
    Fixed result;
    result.fixed_point = this->fixed_point * val.fixed_point;
    return result;
}

Fixed Fixed::operator/(const Fixed &val) const{
    Fixed result;
    result.fixed_point = this->fixed_point / val.fixed_point;
    return result;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;     // Save the current value
    this->fixed_point += 1; // Increment the fixed_point by 1 (i.e., +ε)
    return temp;            // Return the old value (before incrementing)
}