/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:42 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/17 17:38:48 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iomanip>
# include <sstream>

# define WIDTH 10
# define N_INFO 3

class PhoneBook
{
private:
	Contact	_contacts[8]; //ad ogni istanza di phonebook vengono allocate automaticamente 8 istanze di contact
	size_t	_contactCount;

public:
	PhoneBook();

	void	addContact();
	void	searchContact();
	void	printPhoneBook();
	void	displaySavedContacts();
	void	displayHeader();
	void	getFormattedValues(std::string *value, Contact contact);
	bool	findContact();
};

void	printUsageMessage();
bool	getValidInput(std::string prompt, std::string &input);

#endif