/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:34:24 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/06 18:44:29 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

/* ------------------------------------ Orthodox canonical form ----------------------------------- */
Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = Fixed::getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* ------------------------------------ Other constructors ----------------------------------- */

Fixed::Fixed(const int value) {
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _fractionalBits));
}

/* ------------------------------------ Getters and setters ----------------------------------- */

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	if (raw)
		_rawBits = raw;
}

/* ------------------------------------ Member functions ----------------------------------- */

float	Fixed::toFloat(void) const {
	return ((float)_rawBits / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const {
	return (_rawBits >> _fractionalBits);
}

/* ------------------------------------ Overload comparison operators ----------------------------------- */

bool	Fixed::operator>(const Fixed &other) const {
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed &other) const {
	return (other > *this);
}

bool	Fixed::operator>=(const Fixed &other) const {
	return !(*this < other);
}

bool	Fixed::operator<=(const Fixed &other) const {
	return !(*this > other);
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->_rawBits != other._rawBits);
}

/* -------------------- Overload arithmetic operators -------------------- */

Fixed	Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

/* ---------------------- Overload increment operators ---------------------- */

Fixed	Fixed::operator++(void) const {
	return Fixed(this->toFloat() + 1);
}

Fixed	Fixed::operator++(int) const {
	Fixed old = *this;

	operator++();
	return (old);
}

/* ---------------------- Overload decrement operators ---------------------- */

// Fixed	&Fixed::operator--(void) const {
// 	Fixed	result;

// 	result._rawBits--;
// 	return (result);
// }

// Fixed	Fixed::operator--(int) const {
// 	Fixed old = *this;

// 	operator--();
// 	return (old);
// }

/* ------------------------------------ Non-member functions ----------------------------------- */

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}
