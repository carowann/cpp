/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:40:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/07 11:53:40 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

/* ------------------------------------ Orthodox canonical form ----------------------------------- */
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_rawBits = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ------------------------------------ Getters and setters ----------------------------------- */

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	if (raw)
		_rawBits = raw;
}

/* ------------------------------------ Other constructors ----------------------------------- */

Fixed::Fixed(const int value)
{
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_rawBits = roundf(value * (1 << _fractionalBits));
}

/* ------------------------------------ Member functions ----------------------------------- */

float	Fixed::toFloat(void) const
{
	float	value;

	value = (float)_rawBits / (1 << _fractionalBits);
	return (value);
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

/* -------------------------------------------------------------------------- */

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
