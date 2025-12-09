/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:23:42 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/09 18:03:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
private:
	Contact	_contacts[8]; //ad ogni istanza di phonebook vengono allocate automaticamente 8 istanze di contact

public:
	void		addContact();
	void		printPhoneBook();
	static bool	getValidInput();
};

void printUsageMessage();

#endif