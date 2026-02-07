/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:40:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/07 16:26:23 by cwannhed         ###   ########.fr       */
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
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_rawBits = other._rawBits;
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* ------------------------------------ Getters and setters ----------------------------------- */

int Fixed::getRawBits(void) const {
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

/* ------------------------------------ Other constructors ----------------------------------- */

Fixed::Fixed(const int value) {
	_rawBits = value << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

/* ------------------------------------ Member functions ----------------------------------- */

float	Fixed::toFloat(void) const {
	float	value;

	value = (float)_rawBits / (1 << _fractionalBits);
	return (value);
}

int	Fixed::toInt(void) const {
	return (_rawBits >> _fractionalBits);
}

/* -------------------------------------------------------------------------- */

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}
