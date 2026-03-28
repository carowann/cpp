/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:25:56 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/28 11:52:00 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	// OCF
	Point();
	Point(const Point &other);
	Point	&operator=(const Point &other);
	~Point();
	/* -------------------------------------------------------------------------- */
	Point(const float x, const float y);
	// Getters
	const Fixed	&getX() const;
	const Fixed	&getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif