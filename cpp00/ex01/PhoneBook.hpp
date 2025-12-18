/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:42 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/18 14:40:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <iomanip>
# include <sstream>

# define BOLD	"\033[1m"
# define BLUE	"\033[0;34m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

# define WIDTH 10
# define N_INFO 3

class PhoneBook
{
private:
	Contact	_contacts[8]; //ad ogni istanza di phonebook vengono allocate automaticamente 8 istanze di contact
	size_t	_contactCount;
	size_t	_lastIndex;

public:
	PhoneBook();

	void		addContact();
	void		searchContact();
	void		printPhoneBook();
	void		displaySavedContacts();
	void		displayHeader();
	bool		findContact();
	void		printFormattedValues(int index, Contact contact);
	std::string	formattedValue(std::string value);
};

void	printUsageMessage();
bool	getValidInput(std::string prompt, std::string &input);

#endif