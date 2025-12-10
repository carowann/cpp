/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:40 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/10 17:25:09 by cwannhed         ###   ########.fr       */
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
		std::cout << "Error: Field cannot be empty. Please try again." << std::endl;
	}
	return (true);
}

void	PhoneBook::addContact()
{
	std::string	input = "";
	Contact		&c = _contacts[_contactCount];

	std::cout << "\n=== Adding new contact ===\n" << std::endl;
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
	std::cout << "\nContact successfully added at index " << _contactCount << "!\n" << std::endl;
	_contactCount = (_contactCount + 1 ) % 8;
}

void	PhoneBook::printPhoneBook()
{
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << _contacts[i].getContactString();
	}
}

void	PhoneBook::displaySavedContacts()
{
	std::cout << "Displaying saved contacts..." << std::endl;
	for (size_t i = 0; i < static_cast<size_t>(_contactCount); i++)
	{
		std::cout << "Index: " << i << " | "
					<< "First Name: " << _contacts[i].getContactString() << " | "
					<< "Last Name: " << _contacts[i].getContactString() << " | "
					<< "Nickname: " << _contacts[i].getContactString() << std::endl;
	}
	//Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.
	//Each column must be 10 characters wide.  A pipe character (’|’) separates hem. The text must be right-aligned.
	//If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot (’.’)
}
void	PhoneBook::searchContact()
{
	std::cout << "Searching a new contact..." << std::endl;
	displaySavedContacts();
	// prompt the user again for the index of the entry to display
	//If the index is out of range or wrong, define a relevant behavior
	// Otherwise, display thE contact information, one field per line
}
