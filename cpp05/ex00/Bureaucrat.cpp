/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:18:19 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/20 13:42:41 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

/* ------------------------------------ EXCEPTIONS ----------------------------------- */

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

