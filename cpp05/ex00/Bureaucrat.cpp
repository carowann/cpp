/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:18:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/14 20:01:02 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	// if (grade < 1)
	// 	throw Bureaucrat::GradeTooHighException();
	// if (grade > 150)
	// 	throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

/* -------------------------------------------------------------------------- */

std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return(_grade);
}

void	Bureaucrat::incrementGrade() {
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	_grade++;
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
