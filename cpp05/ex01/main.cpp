/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:07:40 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/17 11:36:55 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


void	testHeader(std::string const &testName) {
	std::cout << BOLD << "\n==================== " << testName << " ====================" << RESET << std::endl;
}

void	printOk(std::string const &msg) {
	std::cout << GREEN << "[OK] " << RESET << msg << std::endl;
}

void	printFail(std::string const &msg) {
	std::cout << RED << "[FAIL] " << RESET << msg << std::endl;
}

int	main() {
	// ── TEST 1: Valid Form creation ──────────────────────────────────────────
	testHeader("TEST 1: Valid Form Creation");
	try {
		Form f1("Tax Return", 50, 100);
		printOk("Created: " + f1.getName());
		std::cout << CYAN << f1 << RESET << std::endl;

		Form f2("Presidential Pardon", 1, 1);
		printOk("Created: " + f2.getName());
		std::cout << CYAN << f2 << RESET << std::endl;

		Form f3("Coffee Request", 150, 150);
		printOk("Created: " + f3.getName());
		std::cout << CYAN << f3 << RESET << std::endl;
	}
	catch (std::exception &e) {
		printFail(std::string("Unexpected exception: ") + e.what());
	}

	// ── TEST 2: Form grade too high (grade 0) ───────────────────────────────
	testHeader("TEST 2: Form gradeToSign 0 (Too High)");
	try {
		Form invalid("Invalid", 0, 50);
		printFail("No exception thrown — should have thrown!");
		std::cout << invalid << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		printOk(std::string("Correct exception: ") + e.what());
	}
	catch (std::exception &e) {
		printFail(std::string("Wrong exception type: ") + e.what());
	}

	// ── TEST 3: Form grade too low (grade 151) ──────────────────────────────
	testHeader("TEST 3: Form gradeToExecute 151 (Too Low)");
	try {
		Form invalid("Invalid", 50, 151);
		printFail("No exception thrown — should have thrown!");
		std::cout << invalid << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		printOk(std::string("Correct exception: ") + e.what());
	}
	catch (std::exception &e) {
		printFail(std::string("Wrong exception type: ") + e.what());
	}

	// ── TEST 4: signForm — success ──────────────────────────────────────────
	testHeader("TEST 4: signForm Success (Grade High Enough)");
	try {
		Bureaucrat b("Alice", 10);
		Form f("Budget Approval", 10, 50);
		std::cout << CYAN << b << RESET << std::endl;
		std::cout << CYAN << f << RESET << std::endl;
		b.signForm(f);
		if (f.getIsSigned())
			printOk("Form is now signed");
		else
			printFail("Form should be signed but isn't");
	}
	catch (std::exception &e) {
		printFail(std::string("Unexpected exception: ") + e.what());
	}

	// ── TEST 5: signForm — grade exactly equal to required ──────────────────
	testHeader("TEST 5: signForm Exact Grade (Boundary)");
	try {
		Bureaucrat b("Bob", 42);
		Form f("Expense Report", 42, 100);
		std::cout << CYAN << b << RESET << std::endl;
		std::cout << CYAN << f << RESET << std::endl;
		b.signForm(f);
		if (f.getIsSigned())
			printOk("Form signed at exact boundary grade");
		else
			printFail("Form should be signed at exact boundary");
	}
	catch (std::exception &e) {
		printFail(std::string("Unexpected exception: ") + e.what());
	}

	// ── TEST 6: signForm — failure (grade too low) ───────────────────────────
	testHeader("TEST 6: signForm Failure (Grade Too Low)");
	try {
		Bureaucrat b("Charlie", 150);
		Form f("Top Secret", 1, 1);
		std::cout << CYAN << b << RESET << std::endl;
		std::cout << CYAN << f << RESET << std::endl;
		b.signForm(f);  // signForm handles the exception internally and prints the message
		if (!f.getIsSigned())
			printOk("Form correctly not signed");
		else
			printFail("Form should not be signed");
	}
	catch (std::exception &e) {
		printFail(std::string("Unexpected exception leaked: ") + e.what());
	}

	// ── TEST 7: signForm — already signed ───────────────────────────────────
	testHeader("TEST 7: signForm Already Signed");
	try {
		Bureaucrat b("Diana", 1);
		Form f("Old Form", 50, 50);
		b.signForm(f);
		std::cout << YELLOW << "Signing again..." << RESET << std::endl;
		b.signForm(f);  // should just sign again (or stay signed)
		if (f.getIsSigned())
			printOk("Form remains signed");
	}
	catch (std::exception &e) {
		printFail(std::string("Unexpected exception: ") + e.what());
	}

	// ── TEST 8: Form OCF ─────────────────────────────────────────────────────
	testHeader("TEST 8: Form OCF - Copy Constructor & Assignment");
	try {
		Form original("Original Form", 42, 80);
		std::cout << YELLOW << "Original: " << RESET << original << std::endl;

		Form copy(original);
		std::cout << YELLOW << "Copy:     " << RESET << copy << std::endl;

		Form assigned("Temp", 1, 1);
		assigned = original;
		std::cout << YELLOW << "Assigned: " << RESET << assigned << std::endl;

		// Sign the original and verify copies are unaffected
		Bureaucrat b("Eve", 1);
		original.beSigned(b);
		std::cout << std::endl;
		std::cout << YELLOW << "After signing original:" << RESET << std::endl;
		std::cout << "Original (signed=" << original.getIsSigned() << "): " << original << std::endl;
		std::cout << "Copy     (signed=" << copy.getIsSigned() << "): " << copy << " <- should be unsigned" << std::endl;
		std::cout << "Assigned (signed=" << assigned.getIsSigned() << "): " << assigned << " <- should be unsigned" << std::endl;

		if (!copy.getIsSigned() && !assigned.getIsSigned())
			printOk("Copy and assigned are independent from original");
		else
			printFail("Copy or assigned was affected by signing original");
	}
	catch (std::exception &e) {
		printFail(std::string("Exception: ") + e.what());
	}

	// ── TEST 9: Default constructors ────────────────────────────────────────
	testHeader("TEST 9: Default Constructors");
	try {
		Bureaucrat defB;
		std::cout << CYAN << defB << RESET << std::endl;
		printOk("Default Bureaucrat created");

		Form defF;
		std::cout << CYAN << defF << RESET << std::endl;
		printOk("Default Form created");
	}
	catch (std::exception &e) {
		printFail(std::string("Exception: ") + e.what());
	}

	std::cout << BOLD << "\n============= ALL TESTS COMPLETE =============" << RESET << std::endl;
	return (0);
}