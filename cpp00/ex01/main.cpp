/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:09:53 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/10 15:17:27 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	printUsageMessage();
	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
		{
			std::cout << "Exiting Phonebook..." << std::endl;
			break;
		}
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
	}
	phonebook.printPhoneBook();
	return (0);
}
