/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:34:04 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/10 11:20:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// std::cout << std::endl;

	// // Test arithmetic operators
	// Fixed const	c(10);
	// Fixed const	d(3);

	// std::cout << c << std::endl;
	// std::cout << d << std::endl;
	// std::cout << c + d << std::endl;
	// std::cout << c - d << std::endl;
	// std::cout << c * d << std::endl;
	// std::cout << c / d << std::endl;

	// std::cout << std::endl;

	// // Test comparison operators
	// Fixed		e(5.5f);
	// Fixed		f(5.5f);
	// Fixed		g(10.2f);

	// std::cout << (e < g) << std::endl;
	// std::cout << (e > g) << std::endl;
	// std::cout << (e <= f) << std::endl;
	// std::cout << (e >= f) << std::endl;
	// std::cout << (e == f) << std::endl;
	// std::cout << (e != g) << std::endl;

	// std::cout << std::endl;

	// // Test min/max w/ const
	// Fixed const	h(42.42f);
	// Fixed const	i(21.21f);

	// std::cout << Fixed::min(h, i) << std::endl;
	// std::cout << Fixed::max(h, i) << std::endl;

	// std::cout << std::endl;

	// // Test decrement
	// Fixed		j(10);

	// std::cout << j << std::endl;
	// std::cout << --j << std::endl;
	// std::cout << j << std::endl;
	// std::cout << j-- << std::endl;
	// std::cout << j << std::endl;

	// std::cout << std::endl;

	// // Test w/ negatives
	// Fixed const	k(-5.5f);
	// Fixed const	l(2.5f);

	// std::cout << k << std::endl;
	// std::cout << l << std::endl;
	// std::cout << k + l << std::endl;
	// std::cout << k * l << std::endl;

	// std::cout << std::endl;

	// // Test conversions
	// Fixed const	m(42.42f);

	// std::cout << m << std::endl;
	// std::cout << m.toInt() << std::endl;
	// std::cout << m.toFloat() << std::endl;

	return (0);
}
