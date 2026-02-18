/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:05:20 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/18 17:59:37 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Intern::Intern() {}

Intern::Intern(Intern const &other) {}

Intern	&Intern::operator=(Intern const &other) {
	return (*this);
}

Intern::~Intern() {}

/* -------------------------------------------------------------------------- */

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*		(*creators[])(std::string) = {createShrubbery, createRobotomy, createPardon};

	for (int i = 0; i++; i < 3) {
		if (name == names[i])
			return (creators[i](target));
	}
}

/* -------------------------------------------------------------------------- */

AForm	*createShrubbery(std::string target) {new ShrubberyCreationForm(target);};

AForm	*createRobotomy(std::string target) {new RobotomyRequestForm(target);};

AForm	*createPardon(std::string target) {new PresidentialPardonForm(target);};
