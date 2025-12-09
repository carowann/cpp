/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:40 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/09 18:02:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	printUsageMessage()
{
	std::cout << "========== PhoneBook ==========\n" << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "  • ADD    - Add a new contact" << std::endl;
	std::cout << "  • SEARCH - Display contacts" << std::endl;
	std::cout << "  • EXIT   - Quit program" << std::endl;
}

void	getValidInput()
{
std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
}

void	PhoneBook::addContact()
{
	static int	i = 0;
	std::string input;
	Contact &c = _contacts[i];

	//TODO: check if input field is empty. if it's empty print error message and retry
	std::cout << "Please input the first name: ";

	c.setFirstName(input);

	std::cout << "Please input the last name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	c.setLastName(input);

	std::cout << "Please input the nickname: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	c.setNickName(input);

	std::cout << "Please input the phone number: ";
		std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	c.setPhoneNumber(input);

	std::cout << "Please input the darkest secret: ";
		std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	c.setSecret(input);
	i++;
	if (i == 8)
		i = 0;
	//prompt to input the information of the new contact one field at a time
	// first name, last name, nickname, phone number, and darkest secret
	//A saved contact can’t have empty fields.
	// Once all the fields have been completed, add the contact to the phonebook
}


void	PhoneBook::printPhoneBook()
{
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << _contacts[i].getContactString();
	}
}
