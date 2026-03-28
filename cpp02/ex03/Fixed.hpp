/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:24:31 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/28 11:24:34 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits;

public:
	//OCF
	Fixed();
	Fixed(const Fixed &other);
	Fixed	&operator=(const Fixed &other);
	~Fixed();
	/* -------------------------------------------------------------------------- */
	Fixed(const int value);
	Fixed(const float value);
	// Getters and setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	// Converters
	float	toFloat(void) const;
	int		toInt(void) const;
	// Overload operators
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	//
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(Fixed const &a, Fixed const&b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(Fixed const &a, Fixed const&b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
