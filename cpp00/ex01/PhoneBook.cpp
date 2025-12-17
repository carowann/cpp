/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:45:48 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/17 13:56:45 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0)
{
	std::cout << "PhoneBook constructor" <<  std::endl;
}

void	printUsageMessage()
{
	std::cout << "========== PhoneBook ==========\n" << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "  • ADD    - Add a new contact" << std::endl;
	std::cout << "  • SEARCH - Display contacts" << std::endl;
	std::cout << "  • EXIT   - Quit program" << std::endl;
}

void	PhoneBook::printPhoneBook()
{
	for (size_t i = 0; i < 8; i++)
		std::cout << _contacts[i].getContactString();
}
