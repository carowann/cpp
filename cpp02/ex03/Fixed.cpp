/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:24:38 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/28 11:24:40 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

/* ------------------------------------ Orthodox canonical form ----------------------------------- */

Fixed::Fixed() : _rawBits(0) {
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		_rawBits = other._rawBits;
	}
	return (*this);
}

Fixed::~Fixed() {
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
	Fixed	result;

	result._rawBits = this->_rawBits + other._rawBits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed	result;

	result._rawBits = this->_rawBits - other._rawBits;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed	result;
	long	temp;

	temp = static_cast<long>(this->_rawBits) * static_cast<long>(other._rawBits);
	result._rawBits = static_cast<int>(temp >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed	result;
	long	temp;

	temp = (static_cast<long>(this->_rawBits) << _fractionalBits) / static_cast<long>(other._rawBits);
	result._rawBits = static_cast<int>(temp);
	return (result);
}

/* ---------------------- Overload increment/decrement operators ---------------------- */

Fixed	&Fixed::operator++ (void) {
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed old = *this;

	this->_rawBits++;
	return (old);
}

Fixed	&Fixed::operator-- (void) {
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed old = *this;

	this->_rawBits--;
	return (old);
}

/* -------------------------------------------------------------------------- */

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

/* ------------------------------------ Non-member functions ----------------------------------- */

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}
