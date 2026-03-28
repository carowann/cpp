/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:27:02 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/28 11:46:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Given three points A, B and P:
// - Compute vector AB (the edge of the triangle)
// - Compute vector AP (from A to the point we are checking)
// - The cross product AB x AP gives a signed value:
//     positive -> P is to the left of edge AB
//     negative -> P is to the right of edge AB
//     zero     -> P is exactly on edge AB (collinear)
Fixed	crossProduct(const Point &a, const Point &b, const Point &c) {
	Fixed	abX = b.getX() - a.getX();
	Fixed	abY = b.getY() - a.getY();
	Fixed	acX = c.getX() - a.getX();
	Fixed	acY = c.getY() - a.getY();

	return (abX * acY - abY * acX);
}


// A point is inside triangle ABC if and only if it is on the same side
// of all three edges (AB, BC, CA).
// We check this by computing the cross product for each edge:
// - If all three are positive -> point is to the left of all edges -> inside
// - If all three are negative -> point is to the right of all edges -> inside
// - If any is zero -> point is on an edge or vertex -> outside (return false)
// - If signs are mixed -> point is outside the triangle -> outside
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area1 = crossProduct(a, b, point);
	Fixed	area2 = crossProduct(b, c, point);
	Fixed	area3 = crossProduct(c, a, point);

	if (area1 > 0 && area2 > 0 && area3 > 0)
		return (true);
	if (area1 < 0 && area2 < 0 && area3 < 0)
		return (true);
	return (false);
}
