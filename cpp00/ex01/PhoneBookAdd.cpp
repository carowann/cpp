/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookAdd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:40 by cwannhed          #+#    #+#             */
/*   Updated: 2026/01/05 12:04:09 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact()
{
	std::string	input = "";
	Contact		&contact = _contacts[_lastIndex];

	std::cout << GREEN "\n=== Adding new contact ===\n" RESET << std::endl;
	if (!getValidInput("First name: ", input))
		return;
	contact.setFirstName(input);
	if (!getValidInput("Last name: ", input))
		return;
	contact.setLastName(input);
	if (!getValidInput("Nickname: ", input))
		return;
	contact.setNickName(input);
	if (!getValidInput("Phone number: ", input))
		return;
	contact.setPhoneNumber(input);
	if (!getValidInput("Darkest secret: ", input))
		return;
	contact.setDarkestSecret(input);
	std::cout << "\nContact successfully added at index " << _lastIndex << "!" << std::endl;
	if (_contactCount < 8)
		_contactCount++;
	_lastIndex = (_lastIndex + 1 ) % 8;
}

bool	getValidInput(std::string prompt, std::string &input)
{
	input.clear();
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		if (!input.empty())
			return (true);
		std::cout << RED "Error: Field cannot be empty. Please try again." RESET << std::endl;
	}
	return (true);
}
