/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:04:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 12:41:11 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <cfloat>
# include <cmath>

class ScalarConverter
{
private:
	//OCF
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter	&operator=(ScalarConverter const &);
	~ScalarConverter();
public:
	static void	convert(std::string toConvert);
	static bool	toDouble(std::string const &s, double &out);
	static void	printChar(double value);
	static void	printInt(double value);
	static void	printFloat(double value);
	static void	printDouble(double value);

};

#endif