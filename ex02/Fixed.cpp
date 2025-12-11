#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits) {
}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))) {
}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed::~Fixed() {
}


// Comparateur
Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this != &rhs)
		_value = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& rhs) const {
	return _value > rhs._value;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return _value != rhs._value;
}

// Operation
Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(_value + rhs._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(_value - rhs._value);
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits((_value * rhs._value) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits((_value << _fractionalBits) / rhs._value);
	return result;
}

// Pre
Fixed& Fixed::operator++() {
	_value += 1;
	return *this;
}

// Post
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	_value += 1;
	return tmp;
}

// Pre
Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

// Post
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	_value -= 1;
	return tmp;
}

// Static min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a > b)
        return a;
    return b;
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	return _value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
