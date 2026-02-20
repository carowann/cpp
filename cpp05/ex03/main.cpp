/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:07:40 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/20 13:46:34 by cwannhed         ###   ########.fr       */
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

	// -- TEST 1: Intern creates all 3 valid forms ----------------------------------
	testHeader("TEST 1: Intern creates all 3 valid forms");
	{
		Intern	intern;
		AForm	*scf = intern.makeForm("shrubbery creation", "Home");
		AForm	*rrf = intern.makeForm("robotomy request", "Bender");
		AForm	*ppf = intern.makeForm("presidential pardon", "Pluto");

		if (scf) { printOk("ShrubberyCreationForm created: " + scf->getName()); delete scf; }
		else printFail("ShrubberyCreationForm not created!");

		if (rrf) { printOk("RobotomyRequestForm created: " + rrf->getName()); delete rrf; }
		else printFail("RobotomyRequestForm not created!");

		if (ppf) { printOk("PresidentialPardonForm created: " + ppf->getName()); delete ppf; }
		else printFail("PresidentialPardonForm not created!");
	}

	// -- TEST 2: Invalid form name -------------------------------------------------
	testHeader("TEST 2: Invalid form name");
	{
		Intern	intern;
		AForm	*f = intern.makeForm("coffee request", "Bender");
		if (f == NULL)
			printOk("NULL returned for unknown form name - correct!");
		else {
			printFail("Should have returned NULL!");
			delete f;
		}
	}

	// -- TEST 3: Intern OCF --------------------------------------------------------
	testHeader("TEST 3: Intern OCF (copy + assignment)");
	{
		Intern	a;
		Intern	b(a);
		Intern	c;
		c = a;
		AForm	*f = b.makeForm("presidential pardon", "Arthur Dent");
		if (f) { printOk("Copy of Intern works correctly"); delete f; }
		AForm	*f2 = c.makeForm("robotomy request", "Marvin");
		if (f2) { printOk("Assigned Intern works correctly"); delete f2; }
	}

	// -- TEST 4: Sign + execute via Bureaucrat ------------------------------------
	testHeader("TEST 4: Intern creates form, Bureaucrat signs and executes");
	{
		Intern		intern;
		Bureaucrat	b("Boss", 1);

		AForm	*scf = intern.makeForm("shrubbery creation", "Garden");
		if (scf) {
			b.signForm(*scf);
			b.executeForm(*scf);
			printOk("ShrubberyCreationForm - check Garden_shrubbery file!");
			delete scf;
		}

		AForm	*rrf = intern.makeForm("robotomy request", "Bender");
		if (rrf) {
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}

		AForm	*ppf = intern.makeForm("presidential pardon", "Zaphod");
		if (ppf) {
			b.signForm(*ppf);
			b.executeForm(*ppf);
			delete ppf;
		}
	}

	// -- TEST 5: Execute without signing ------------------------------------------
	testHeader("TEST 5: Execute unsigned form");
	{
		Intern		intern;
		Bureaucrat	b("Boss", 1);
		AForm		*rrf = intern.makeForm("robotomy request", "Bender");
		if (rrf) {
			b.executeForm(*rrf);
			delete rrf;
		}
	}

	// -- TEST 6: Grade too low to execute -----------------------------------------
	testHeader("TEST 6: Grade too low to execute");
	{
		Intern		intern;
		Bureaucrat	signer("Signer", 1);
		Bureaucrat	weakExec("WeakExec", 150);
		AForm		*rrf = intern.makeForm("robotomy request", "Bender");
		if (rrf) {
			signer.signForm(*rrf);
			weakExec.executeForm(*rrf);
			delete rrf;
		}
	}

	return (0);
}