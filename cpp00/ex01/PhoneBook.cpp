/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:40 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/05 18:27:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void printUsageMessage()
{
	std::cout << "========== PhoneBook ==========\n" << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "  • ADD    - Add a new contact" << std::endl;
	std::cout << "  • SEARCH - Display contacts" << std::endl;
	std::cout << "  • EXIT   - Quit program" << std::endl;
	std::cout << "\nEnter command: ";
}

void PhoneBook::addContact()
{
	std::cout << "Please input the first name: ";
	std::cout << "Please input the last name: ";
	std::cout << "Please input the nickname: ";
	std::cout << "Please input the phone number: ";
	std::cout << "Please input the darkest secret: ";
	//prompt to input the information of the new contact one field at a time
	// first name, last name, nickname, phone number, and darkest secret
	//A saved contact can’t have empty fields.
	// Once all the fields have been completed, add the contact to the phonebook
}