/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:03:35 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/23 17:00:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]) {
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Please input a parameter to convert" << std::endl;
	return (0);
}
