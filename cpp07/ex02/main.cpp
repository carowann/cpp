/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:36:37 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/27 15:52:06 by cwannhed         ###   ########.fr       */
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

// #define MAX_VAL 750
// int main(int, char **)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int *mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	// SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete[] mirror;//
// 	return 0;
// }