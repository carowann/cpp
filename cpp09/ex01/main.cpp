/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:54:27 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/10 17:22:10 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << RED << "Usage: " << argv[0] << " <inverted Polish mathematical expression>" << std::endl;
		return (1);
	}
	try {
		RPN	rpn;
		rpn.parseExpression(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
}
