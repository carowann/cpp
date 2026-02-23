/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:05:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/23 13:37:38 by cwannhed         ###   ########.fr       */
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

void	ScalarConverter::convert(std::string toConvert) {
	// if (isCharLiteral(toConvert)) {
	// 	// estrai il char, stampa le 4 conversioni
	// }
	// else if (isPseudoLiteral(toConvert)) {
	// 	// stampa i valori speciali
	// }
	// else if (isFloat(toConvert)) {
	// 	// strtof, poi stampa le 4 conversioni
	// }
	// else if (isDouble(toConvert)) {
	// 	// strtod, poi stampa le 4 conversioni
	// }
	// else {
	// 	// strtol come int, poi stampa le 4 conversioni
	// }
}
