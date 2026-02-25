/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:59:12 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/25 14:53:43 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

template <typename T>
void	print(T const &a) {
	std::cout << a << std::endl;
}

template <typename T>
void	doubleValue(T &a) {
	a *= 2;
}

template <typename T>
void	printUpperCase(T const &a) {
	(void)a;
	std::cout << "not a string" << std::endl;
}

template <>
void	printUpperCase<std::string>(std::string const &a) {
	for (size_t i = 0; i < a.size(); i++)
		std::cout << static_cast<char>(std::toupper(a[i]));
	std::cout << std::endl;
}

int	main() {
	testHeader("Int array - print");
	int	intArray[5] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print<int>);

	testHeader("Int array - double value (non-const function)");
	iter(intArray, 5, doubleValue<int>);
	iter(intArray, 5, print<int>);

	testHeader("String array - print");
	std::string	stringArray[3] = {"hello", "fortytwo", "world"};
	iter(stringArray, 3, print<std::string>);

	testHeader("String array - uppercase (custom function)");
	iter(stringArray, 3, printUpperCase<std::string>);

	testHeader("Const int array - print");
	const int	constArray[4] = {10, 20, 30, 40};
	iter(constArray, 4, print<int>);

	return (0);
}