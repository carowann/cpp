/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:10:33 by cwannhed          #+#    #+#             */
/*   Updated: 2026/03/03 16:34:17 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

int	randomNumber() { return (std::rand() % 100000); }

int	main() {

	testHeader("Test 0: subject example (expect: 2, 14)");
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 1: addNumber on Span(0) (expect: exception)");
	try {
		Span sp = Span(0);
		sp.addNumber(42);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 2: addNumber on full span (expect: exception)");
	try {
		Span sp = Span(1);
		sp.addNumber(42);
		sp.addNumber(99);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 3: shortestSpan with 1 element (expect: exception)");
	try {
		Span sp = Span(5);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 4: longestSpan with 0 elements (expect: exception)");
	try {
		Span sp = Span(5);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 5: all identical numbers (expect: shortest=0, longest=0)");
	try {
		Span sp = Span(4);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 6: addRange with vector of 13000 elements");
	try {
		Span				sp(15000);
		std::vector<int>	ve(13000);
		std::srand(std::time(0));
		std::generate(ve.begin(), ve.end(), randomNumber);
		sp.addRange(ve.begin(), ve.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 7: addRange with list of 13000 elements");
	try {
		Span			sp(15000);
		std::list<int>	li(13000);
		std::srand(std::time(0));
		std::generate(li.begin(), li.end(), randomNumber);
		sp.addRange(li.begin(), li.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 8: addRange exceeds capacity (expect: exception)");
	try {
		Span				sp(5000);
		std::vector<int>	ve(8000);
		std::generate(ve.begin(), ve.end(), randomNumber);
		sp.addRange(ve.begin(), ve.end());
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	testHeader("Test 9: addRange exceeds remaining capacity (expect: exception)");
	try {
		Span				sp(5000);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::vector<int>	ve(5000);
		std::generate(ve.begin(), ve.end(), randomNumber);
		sp.addRange(ve.begin(), ve.end());
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return (0);
}
