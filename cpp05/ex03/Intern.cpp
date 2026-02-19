/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:05:20 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/19 14:23:19 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Intern::Intern() {}

Intern::Intern(Intern const &) {}

Intern	&Intern::operator=(Intern const &) {
	return (*this);
}

Intern::~Intern() {}

/* -------------------------------------------------------------------------- */

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		(*creators[])(std::string) = {createShrubbery, createRobotomy, createPardon};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Error! The intern can't create a " << name << " form. :(" << std::endl;
	return (NULL);
}

/* -------------------------------------------------------------------------- */

AForm	*createShrubbery(std::string target) {return new ShrubberyCreationForm(target);};

AForm	*createRobotomy(std::string target) {return new RobotomyRequestForm(target);};

AForm	*createPardon(std::string target) {return new PresidentialPardonForm(target);};
