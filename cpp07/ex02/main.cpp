/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:37 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/27 15:39:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

int	main() {
	testHeader("Test 1: Construction with no parameter"); {
	Array<char>	charArray;
	Array<int>	intArray;

	for (unsigned int i = 0 ; i < charArray.size(); i++)
		std::cout << charArray[i] << std::endl;
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	}

	testHeader("Test 2: Construction with size parameter"); {
	Array<char>	charArray(5);
	Array<int>	intArray(5);
	for (unsigned int i = 0 ; i < charArray.size(); i++)
		std::cout << charArray[i] << std::endl;
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	}

	testHeader("Test 3: Construction by copy constructor"); {
	Array<int>	intArray(5);
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		intArray[i] = 42;
	Array<int>	copyArray(intArray);
	std::cout << "Original array :" << std::endl;
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	std::cout << "Copy array :" << std::endl;
	for (unsigned int i = 0 ; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;
	std::cout << "Modifying original, copy should not change:" << std::endl;
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		intArray[i] = 0;
	for (unsigned int i = 0 ; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;
	}

	testHeader("Test 4: Assignment operator"); {
	Array<int>	intArray(5);
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		intArray[i] = 42;
	Array<int>	copyArray(10);
	for (unsigned int i = 0 ; i < copyArray.size(); i++)
		copyArray[i] = 5;
	std::cout << "First array :" << std::endl;
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	std::cout << "Second array :" << std::endl;
	for (unsigned int i = 0 ; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;
	copyArray = intArray;
	std::cout << "Second array after assignment:" << std::endl;
	for (unsigned int i = 0 ; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;
	std::cout << "Modifying original, copy should not change:" << std::endl;
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		intArray[i] = 0;
	for (unsigned int i = 0 ; i < copyArray.size(); i++)
		std::cout << copyArray[i] << std::endl;
	}

	testHeader("Test 5: Out of bounds exception"); {
	Array<int>	intArray(5);
	for (unsigned int i = 0 ; i < intArray.size(); i++)
		intArray[i] = 42;
	try {
		std::cout << intArray[intArray.size() + 5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	}

	testHeader("Test 6: Template with std::string"); {
	Array<std::string>	strArray(3);
	strArray[0] = "hello";
	strArray[1] = "world";
	strArray[2] = "42";
	for (unsigned int i = 0 ; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;
	}
}