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
	// Overload comparison operators
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	// Overload arithmetic operators
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	// Overload increment operators
	Fixed	&operator++(void);
	Fixed	operator++(int);
	// Overload decrement operators
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&min(Fixed const &a, Fixed const&b);
};

// MUST be non-member function because the left operand is the stream:
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif