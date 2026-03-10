/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:38:50 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/10 11:47:52 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << RED << "Usage: " << argv[0] << " <filename>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange	btcExchange;
		btcExchange.validateInputFile(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}