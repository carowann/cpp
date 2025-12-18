/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookAdd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:40 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/18 14:43:13 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact()
{
	std::string	input = "";
	Contact		&c = _contacts[_lastIndex];

	std::cout << GREEN "\n=== Adding new contact ===\n" RESET << std::endl;
	if (!getValidInput("First name: ", input))
		return;
	c.setFirstName(input);
	if (!getValidInput("Last name: ", input))
		return;
	c.setLastName(input);
	if (!getValidInput("Nickname: ", input))
		return;
	c.setNickName(input);
	if (!getValidInput("Phone number: ", input))
		return;
	c.setPhoneNumber(input);
	if (!getValidInput("Darkest secret: ", input))
		return;
	c.setDarkestSecret(input);
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
