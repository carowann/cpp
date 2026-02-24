/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:04:08 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 17:00:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "utils.hpp"

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
};

#endif