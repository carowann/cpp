/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:37 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/10 17:34:35 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: _firstName(), _lastName(),
		_nickname(), _phoneNumber(), _darkestSecret()
{
	std::cout << "Contact constructor" << std::endl;
}

void	Contact::setFirstName(std::string name)
{
	if (!name.empty())
		_firstName = name;
}

void	Contact::setLastName(std::string name)
{
	if (!name.empty())
		_lastName = name;
}

void	Contact::setNickName(std::string name)
{
	if (!name.empty())
		_nickname = name;
}

void	Contact::setPhoneNumber(std::string number)
{
	if (!number.empty())
		_phoneNumber = number;
}

void	Contact::setDarkestSecret(std::string secret)
{
	if (!secret.empty())
		_darkestSecret = secret;
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickName() const
{
	return (_nickname);
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
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
