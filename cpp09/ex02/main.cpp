/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:34:26 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/10 18:24:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << RED << "Usage: " << argv[0] << " <n1> <n2> <n3> ..." << std::endl;
		return (1);
	}
	try {

	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
}
