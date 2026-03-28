/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:26:27 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/28 11:33:31 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		const_cast<Fixed &>(_x) = other._x;
		const_cast<Fixed &>(_y) = other._y;
	}
	return (*this);
}

Point::~Point() {}

/* -------------------------------------------------------------------------- */

Point::Point(const float x, const float y) : _x(x), _y(y) {}

/* ------------------------------------ Getters ----------------------------------- */

const Fixed	&Point::getX() const { return (_x); }

const Fixed	&Point::getY() const { return (_y); }

