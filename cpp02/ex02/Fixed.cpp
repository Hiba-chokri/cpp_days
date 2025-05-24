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

Fixed	Fixed::operator++()
{
	Fixed	obj;

	obj.fixedPointValue = ++this->fixedPointValue;
	return (obj);
}

Fixed	Fixed::operator++(int)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue++;
	return (obj);
}

Fixed	Fixed::operator--()
{
	Fixed	obj;

	obj.fixedPointValue = --this->fixedPointValue;
	return (obj);
}

Fixed	Fixed::operator--(int)
{
	Fixed	obj;

	obj.fixedPointValue = this->fixedPointValue--;
	return (obj);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if(fixed1 < fixed2)
		return fixed1;
    return fixed2;	
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if(fixed1 < fixed2)
		return fixed1;
    return fixed2;
}
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if(fixed1 > fixed2)
		return fixed1;
    return fixed2;	
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if(fixed1 > fixed2)
	return fixed1;
return fixed2;	
}
