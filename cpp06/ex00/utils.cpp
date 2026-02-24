/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:49:53 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 16:50:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


bool toDouble(std::string const &s, double &out) {
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
	return (false);
}

void printChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void printInt(double value) {
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(double value) {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else if (value > FLT_MAX || value < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(value) << "f" << std::endl;
}

void printDouble(double value) {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "double: " << value << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
