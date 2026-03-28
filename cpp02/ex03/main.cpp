/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:24:15 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/28 11:56:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {

	// Triangle with vertices at (0,0), (4,0), (0,4)
	Point const	a(0.0f, 0.0f);
	Point const	b(4.0f, 0.0f);
	Point const	c(0.0f, 4.0f);

	std::cout << "Triangle: (0,0) (4,0) (0,4)" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	// Test: point clearly inside
	Point const	p1(1.0f, 1.0f);
	std::cout << "inside     (1,1):      " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;

	// Test: point clearly outside
	Point const	p2(5.0f, 5.0f);
	std::cout << "outside    (5,5):      " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;

	// Test: point on a vertex
	Point const	p3(0.0f, 0.0f);
	std::cout << "vertex     (0,0):      " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;

	// Test: point on an edge
	Point const	p4(2.0f, 0.0f);
	std::cout << "edge       (2,0):      " << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;

	// Test: point on the hypotenuse
	Point const	p5(2.0f, 2.0f);
	std::cout << "hypotenuse (2,2):      " << (bsp(a, b, c, p5) ? "true" : "false") << std::endl;

	// Test: point just inside
	Point const	p6(0.1f, 0.1f);
	std::cout << "just inside (0.1,0.1): " << (bsp(a, b, c, p6) ? "true" : "false") << std::endl;

	std::cout << std::endl;

	// Triangle with negative coordinates
	Point const	d(-1.0f, -1.0f);
	Point const	e(-4.0f,  0.0f);
	Point const	f( 0.0f, -4.0f);

	std::cout << "Triangle: (-1,-1) (-4,0) (0,-4)" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	// Test: point on a vertex
	Point const	p7(-1.0f, -1.0f);
	std::cout << "vertex     (-1,-1):    " << (bsp(d, e, f, p7) ? "true" : "false") << std::endl;

	// Test: point inside (centroid: x=-1.67, y=-1.67)
	Point const	p8(-1.5f, -1.5f);
	std::cout << "inside     (-1.5,-1.5):" << (bsp(d, e, f, p8) ? "true" : "false") << std::endl;

	return (0);
}
