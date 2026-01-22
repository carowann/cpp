/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:40:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/22 17:32:04 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_nFractBits = 8;

/* ------------------------------------ Orthodox canonical form ----------------------------------- */
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = Fixed::getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other.getRawBits();
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
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	if (raw)
		_value = raw;
}

/* ------------------------------------ Other constructors ----------------------------------- */

Fixed::Fixed(const int value)
{
	_value = value << _nFractBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _nFractBits));
}

/* ------------------------------------ Member functions ----------------------------------- */

float	Fixed::toFloat(void) const
{
	float	value;

	value = (float)_value / (1 << _nFractBits);
	return (value);
}

int	Fixed::toInt(void) const
{
	return (_value >> _nFractBits);
}

/* -------------------------------------------------------------------------- */

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
