/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:07:40 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/16 16:49:59 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

int	main() {

	// Test 1: Valid construction
	testHeader("TEST 1: Valid Bureaucrat Creation");
	try {
		Bureaucrat b1("Alice", 75);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Bob", 1);
		std::cout << b2 << std::endl;

		Bureaucrat b3("Charlie", 150);
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
	}

	// Test 2: Construction with invalid grade (too high)
	testHeader("TEST 2: Construction with Grade 0 (Too High)");
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Wrong exception: " << e.what() << RESET << std::endl;
	}

	// Test 3: Construction with invalid grade (too low)
	testHeader("TEST 3: Construction with Grade 151 (Too Low)");
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Wrong exception: " << e.what() << RESET << std::endl;
	}

	// Test 4: Increment from grade 2 to 1 (valid)
	testHeader("TEST 4: Increment Grade 2 -> 1 (Valid)");
	try {
		Bureaucrat b("David", 2);
		std::cout << "Before: " << b << std::endl;
		b.incrementGrade();
		std::cout << "After:  " << b << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// Test 5: Increment from grade 1 (should throw)
	testHeader("TEST 5: Increment Grade 1 (Should Throw)");
	try {
		Bureaucrat b("Eve", 1);
		std::cout << "Before: " << b << std::endl;
		b.incrementGrade();
		std::cout << "After:  " << b << std::endl; // This should not print
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// Test 6: Decrement from grade 149 to 150 (valid)
	testHeader("TEST 6: Decrement Grade 149 -> 150 (Valid)");
	try {
		Bureaucrat b("Frank", 149);
		std::cout << "Before: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After:  " << b << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// Test 7: Decrement from grade 150 (should throw)
	testHeader("TEST 7: Decrement Grade 150 (Should Throw)");
	try {
		Bureaucrat b("Grace", 150);
		std::cout << "Before: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After:  " << b << std::endl; // This should not print
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// Test 8: Copy constructor and assignment operator
	testHeader("TEST 8: OCF - Copy Constructor & Assignment");
	try {
		Bureaucrat original("Henry", 42);
		std::cout << "Original: " << original << std::endl;

		Bureaucrat copy(original);
		std::cout << "Copy:     " << copy << std::endl;

		Bureaucrat assigned("Temp", 100);
		assigned = original;
		std::cout << "Assigned: " << assigned << std::endl;

		// Verify independence
		original.incrementGrade();
		std::cout << "\nAfter incrementing original:" << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << " (should be unchanged)" << std::endl;
		std::cout << "Assigned: " << assigned << " (should be unchanged)" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// Test 9: Default constructor
	testHeader("TEST 9: Default Constructor");
	try {
		Bureaucrat def;
		std::cout << def << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n============= ALL TESTS COMPLETE =============" << std::endl;
	return (0);
}
