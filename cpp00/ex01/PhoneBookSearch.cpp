/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookSearch.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:44:59 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/17 17:43:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::searchContact()
{
	std::string	input;

	if (_contactCount == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return ;
	}
	displaySavedContacts();
	while (!findContact());
}

void	PhoneBook::displaySavedContacts()
{
	std::string values[N_INFO];

	displayHeader();
	std::cout << std::right; //right adjustment (adds fill characters to the left)
	for (size_t i = 0; i < _contactCount; i++)
	{
		getFormattedValues(values, _contacts[i]);
		std::cout << std::setw(WIDTH) << i << "|";
		for (size_t j = 0; j < N_INFO; j++)
			std::cout << std::setw(WIDTH) << values[j] << "|";
		std::cout << std::endl;
	}
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

void	PhoneBook::getFormattedValues(std::string *value, Contact contact)
{
	static std::string (Contact::*functs[N_INFO])() const = {
		&Contact::getFirstName,
		&Contact::getLastName,
		&Contact::getNickName };

	for (int i = 0; i < N_INFO; i++)
	{
		value[i] = (contact.*functs[i])();
		if (value[i].length() > WIDTH)
		{
			value[i].resize(WIDTH - 1);
			value[i].append(".");
		}
	}
}

bool	PhoneBook::findContact()
{
	size_t			index;
	std::string		input;

	std::cout << "\nPlease input index [0, " << _contactCount << ") of entry to display\n";
	std::getline(std::cin, input);
	std::istringstream	stream(input);
	stream >> index;
	if (index < 0 || index >= _contactCount)
		return (false);
	std::cout << _contacts[index].getContactString();
	return (true);
}
