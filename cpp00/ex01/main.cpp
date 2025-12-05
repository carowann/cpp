/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:09:53 by cwannhed          #+#    #+#             */
/*   Updated: 2025/12/05 18:34:08 by cwannhed         ###   ########.fr       */
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
		std::getline(std::cin, input);
		if (input.compare("ADD"))
		{
			phonebook.addContact();
		}
		else if (input.compare("SEARCH"))
		{
			//Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.
			//Each column must be 10 characters wide.  A pipe character (’|’) separates hem. The text must be right-aligned.
			//If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot (’.’)
			// prompt the user again for the index of the entry to display
			//If the index is out of range or wrong, define a relevant behavior
			// Otherwise, display thE contact information, one field per line
		}
		else if (input.compare("EXIT"))
			break;
	}
	return (0);
}
