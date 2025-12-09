/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:37 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/09 17:28:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: _firstName(), _lastName(),
		_nickname(), _phoneNumber(), _darkestSecret()
{
	std::cout << "Costruito er contatto" << std::endl;
}

void	Contact::setFirstName(std::string input)
{
	_firstName = input;
}

void	Contact::setLastName(std::string input)
{
	_lastName = input;
}


void	Contact::setNickName(std::string input)
{
	_nickname = input;
}


void	Contact::setPhoneNumber(std::string input)
{
	_phoneNumber = input;
}

void	Contact::setSecret(std::string input)
{
	_darkestSecret = input;
}

std::string	Contact::getContactString()
{
	std::string contactString;

	contactString = "First Name: " + _firstName + "\n"
			+ "Last Name: " + _lastName + "\n"
			+ "Nickname: " + _nickname + "\n"
			+ "Phone number: " + _phoneNumber + "\n"
			+ "Darkest secret: " + _darkestSecret + "\n";
	return (contactString);
}
