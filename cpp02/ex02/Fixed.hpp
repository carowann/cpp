#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_nFractBits;

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
	Fixed	operator++(void) const;
	Fixed	operator++(int) const;
	// Overload decrement operators
	Fixed	operator--(void) const;
	Fixed	operator--(int) const;
};

// MUST be non-member function because the left operand is the stream:
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif