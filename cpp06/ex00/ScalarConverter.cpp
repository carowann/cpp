/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:05:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 16:50:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ------------------------------------ OCF ----------------------------------- */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &) {
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

/* -------------------------------------------------------------------------- */

void ScalarConverter::convert(std::string toConvert) {
	double	value;

	if (!toDouble(toConvert, value)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
