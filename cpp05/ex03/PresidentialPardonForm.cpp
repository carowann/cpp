/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:08:00 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/18 15:085 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ------------------------------------ OCF ----------------------------------- */

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default target") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

/* -------------------------------------------------------------------------- */

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
