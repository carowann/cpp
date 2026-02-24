/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:47:34 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/24 16:49:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <cfloat>
# include <cmath>

bool	toDouble(std::string const &s, double &out);
void	printChar(double value);
void	printInt(double value);
void	printFloat(double value);
void	printDouble(double value);

#endif