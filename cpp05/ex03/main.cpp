/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:07:40 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/19 14:24:00 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

	// -- TEST 1: Valid Forms creation w/ makeForm -------------------------------------------
	testHeader("TEST 1: Valid Forms Creation w/ makeForm");
	try {
		Intern	someRandomIntern;
		AForm	*scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Home");

		printOk("Created: " + scf->getName());
		std::cout << CYAN << *scf << RESET << std::endl;

		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		printOk("Created: " + rrf->getName());
		std::cout << CYAN << *rrf << RESET << std::endl;

		AForm	*ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Pluto");
		printOk("Created: " + ppf->getName());
		std::cout << CYAN << *ppf << RESET << std::endl;

		delete scf;
		delete rrf;
		delete ppf;
	}
	catch (std::exception &e) {
		printFail(std::string("Unexpected exception: ") + e.what());
	}

	// // -- TEST 2: Grade too low to execute --------------------------------------
	// testHeader("TEST 2: Grade too low to execute");
	// try {
	// 	ShrubberyCreationForm	sf("Home");
	// 	Bureaucrat				signer("Boss", 1);
	// 	Bureaucrat				executor("Intern", 150);

	// 	signer.signForm(sf);
	// 	sf.execute(executor);
	// 	printFail("No exception thrown - should have thrown!");
	// }
	// catch (AForm::GradeTooLowException &e) {
	// 	printOk(std::string("Correct exception caught: ") + e.what());
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Wrong exception type: ") + e.what());
	// }

	// try {
	// 	RobotomyRequestForm		rf("Pippo");
	// 	Bureaucrat				signer("Boss", 1);
	// 	Bureaucrat				executor("Intern", 150);

	// 	signer.signForm(rf);
	// 	rf.execute(executor);
	// 	printFail("No exception thrown - should have thrown!");
	// }
	// catch (AForm::GradeTooLowException &e) {
	// 	printOk(std::string("Correct exception caught: ") + e.what());
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Wrong exception type: ") + e.what());
	// }

	// try {
	// 	PresidentialPardonForm	pf("Pasquale");
	// 	Bureaucrat				signer("Boss", 1);
	// 	Bureaucrat				executor("Intern", 150);

	// 	signer.signForm(pf);
	// 	pf.execute(executor);
	// 	printFail("No exception thrown - should have thrown!");
	// }
	// catch (AForm::GradeTooLowException &e) {
	// 	printOk(std::string("Correct exception caught: ") + e.what());
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Wrong exception type: ") + e.what());
	// }

	// // -- TEST 3: Execute unsigned form -----------------------------------------
	// testHeader("TEST 3: Execute unsigned form");
	// try {
	// 	ShrubberyCreationForm	sf("Home");
	// 	Bureaucrat				b("Gardener", 1);

	// 	sf.execute(b);
	// 	printFail("No exception thrown - should have thrown!");
	// }
	// catch (AForm::NotSignedException &e) {
	// 	printOk(std::string("Correct exception caught: ") + e.what());
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Wrong exception type: ") + e.what());
	// }

	// // -- TEST 4: executeForm success -------------------------------------------
	// testHeader("TEST 4: executeForm - success");
	// try {
	// 	ShrubberyCreationForm	sf("Home");
	// 	Bureaucrat				b("Gardener", 137);

	// 	b.signForm(sf);
	// 	b.executeForm(sf);
	// 	printOk("ShrubberyCreationForm executed - check Home_shrubbery file!");
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Unexpected exception: ") + e.what());
	// }

	// try {
	// 	RobotomyRequestForm		rf("Pippo");
	// 	Bureaucrat				b("Robot", 45);

	// 	b.signForm(rf);
	// 	b.executeForm(rf);
	// 	printOk("RobotomyRequestForm executed successfully!");
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Unexpected exception: ") + e.what());
	// }

	// try {
	// 	PresidentialPardonForm	pf("Pasquale");
	// 	Bureaucrat				b("President", 5);

	// 	b.signForm(pf);
	// 	b.executeForm(pf);
	// 	printOk("PresidentialPardonForm executed successfully!");
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Unexpected exception: ") + e.what());
	// }

	// // -- TEST 5: Copy and assignment -------------------------------------------
	// testHeader("TEST 5: Copy and assignment");
	// try {
	// 	ShrubberyCreationForm	sf1("Garden");
	// 	Bureaucrat				b("Boss", 1);
	// 	b.signForm(sf1);

	// 	ShrubberyCreationForm	sf2(sf1);
	// 	printOk("Copy constructor OK - isSigned: " + std::string(sf2.getIsSigned() ? "true" : "false"));

	// 	ShrubberyCreationForm	sf3("Other");
	// 	sf3 = sf1;
	// 	printOk("Assignment operator OK - isSigned: " + std::string(sf3.getIsSigned() ? "true" : "false"));
	// }
	// catch (std::exception &e) {
	// 	printFail(std::string("Unexpected exception: ") + e.what());
	// }

	return (0);
}
