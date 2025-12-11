#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n * 256;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * 256);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &b)	
		this->_value = b._value;
	return *this;
}

float Fixed::toFloat() const
{
	return ((float)_value / 256);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}

int Fixed::toInt() const
{
	return (_value / 256);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}