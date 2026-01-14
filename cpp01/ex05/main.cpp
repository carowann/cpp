/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:41:30 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/14 16:34:26 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void ) {
	Harl	harl1;
	Harl	harl2;

	std::cout << "+++ First Harl messages: +++" << std::endl;
	harl1.complain("");
	harl1.complain("DEBUG");
	harl1.complain("WARNING");
	harl1.complain("INFO");
	harl1.complain("ERROR");
	std::cout << "+++ Second Harl messages: +++" << std::endl;
	harl2.complain("INFO");
	harl2.complain("INFO");
	harl2.complain("ERROR");
	harl2.complain("ERROR");
	harl2.complain("DEBUG");
	harl2.complain("WARNING");
	harl2.complain("INFO");
	return (0);
}
