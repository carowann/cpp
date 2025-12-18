/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:45:48 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/18 14:43:37 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _lastIndex(0)
{
	std::cout << "PhoneBook constructor\n" <<  std::endl;
}

void	printUsageMessage()
{
	std::cout << BLUE "========== PhoneBook ==========\n" RESET << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "  • " << BOLD "ADD" RESET << "      - Add a new contact" << std::endl;
	std::cout << "  • " << BOLD "SEARCH" RESET << "   - Display contacts" << std::endl;
	std::cout << "  • " << BOLD "EXIT" RESET << "     - Quit program" << std::endl;
}

void	PhoneBook::printPhoneBook()
{
	for (size_t i = 0; i < 8; i++)
		std::cout << _contacts[i].getContactString();
}
