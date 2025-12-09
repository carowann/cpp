/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:09:53 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/09 17:21:03 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string		input;

	printUsageMessage();
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
		{
			std::cout << "Searching a new contact..." << std::endl;
			//Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.
			//Each column must be 10 characters wide.  A pipe character (’|’) separates hem. The text must be right-aligned.
			//If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot (’.’)
			// prompt the user again for the index of the entry to display
			//If the index is out of range or wrong, define a relevant behavior
			// Otherwise, display thE contact information, one field per line
		}
		else if (input == "EXIT"|| std::cin.eof())
			break;
	}
	phonebook.printPhoneBook();
	return (0);
}
