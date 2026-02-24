/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:05:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 12:19:10 by cwannhed         ###   ########.fr       */
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

/* -------------------------------------------------------------------------- */

bool ScalarConverter::toDouble(std::string const &s, double &out) {
	char	*end;

	if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]))) {
		out = static_cast<double>(s[0]);
		return (true);
	}
	out = strtod(s.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
		return (true);
	if (*end == '\0')
		return (true);
	return false;
}

void ScalarConverter::printChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else if (value > FLT_MAX || value < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
					<< static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::printPseudo(std::string const &s) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::string base = s;
	if (base[base.size() - 1] == 'f')
		base = base.substr(0, base.size() - 1);
	std::cout << "float: " << base << "f" << std::endl;
	std::cout << "double: " << base << std::endl;
}