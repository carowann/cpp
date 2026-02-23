/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:04:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/23 13:22:59 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>

class ScalarConverter
{
private:
	/* data */
public:
	//OCF
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter	&operator=(ScalarConverter const &);
	~ScalarConverter();
	//
	static void	convert(std::string toConvert);
};

#endif