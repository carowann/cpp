/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookSearch.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:44:59 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/18 14:30:00 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::searchContact()
{
	std::string	input;

	if (_contactCount == 0)
	{
		std::cout << "\nPhonebook is empty. Please add at least 1 contact first." << std::endl;
		return ;
	}
	displaySavedContacts();
	while (!findContact());
}

void	PhoneBook::displaySavedContacts()
{
	displayHeader();
	std::cout << std::right; //right adjustment (adds fill characters to the left)
	for (size_t i = 0; i < _contactCount; i++)
		printFormattedValues(i, _contacts[i]);
}

void	PhoneBook::displayHeader()
{
	std::cout << "\n"
			<< std::setw(WIDTH) << "INDEX" << "|"
			<< std::setw(WIDTH) << "FIRST NAME" << "|"
			<< std::setw(WIDTH) << "LAST NAME" << "|"
			<< std::setw(WIDTH) << "NICKNAME" << "|"
			<< std::endl;
}

void	PhoneBook::printFormattedValues(int index, Contact contact)
{
	std::cout << std::setw(WIDTH) << index << "|";
	std::cout << std::setw(WIDTH) << formattedValue(contact.getFirstName()) << "|";
	std::cout << std::setw(WIDTH) << formattedValue(contact.getLastName()) << "|";
	std::cout << std::setw(WIDTH) << formattedValue(contact.getNickName()) << "|";
	std::cout << std::endl;
}

std::string	PhoneBook::formattedValue(std::string value)
{
	if (value.length() > WIDTH)
	{
		value.resize(WIDTH - 1);
		value.append(".");
	}
	return (value);
}

bool	PhoneBook::findContact()
{
	int			index;
	std::string	input;
	char		extra;

	extra = 0;
	index = 0;
	input = "";
	std::cout << "\nPlease input index {";
	for (int i = 0; i < static_cast<int>(_contactCount) - 1; i++)
		std::cout << i << ", ";
	std::cout << _contactCount - 1 << "}" << std::endl;
	if (!std::getline(std::cin, input))
		return (false);
	std::istringstream	stream(input);
	if (!(stream >> index))
	{
		std::cout << RED "Error. Invalid input: not a number" RESET<< std::endl;
		return (false);
	}
	if (index < 0 || index >= static_cast<int>(_contactCount))
	{
		std::cout << RED "Error. Index out of range!" RESET << std::endl;
		return (false);
	}
	stream >> extra;
	if (extra)
	{
		std::cout << RED "Error. Extra characters after index input!" RESET << std::endl;
		return (false);
	}
	std::cout << _contacts[index].getContactString();
	return (true);
}
