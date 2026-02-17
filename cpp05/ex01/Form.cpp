/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:09:33 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/17 11:43:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ------------------------------------ OCF ----------------------------------- */

Form::Form() :
	_name("Default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150) {}

Form::Form(Form const &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

Form	&Form::operator=(Form const &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

/* -------------------------------------------------------------------------- */

Form::Form(std::string const &name, int const gradeToSign, int const gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
}

/* ------------------------------------ GETTERS ----------------------------------- */

std::string	Form::getName() const {
	return (_name);
}

bool	Form::getIsSigned() const {
	return (_isSigned);
}

int	Form::getGradeToSign() const {
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const {
	return (_gradeToExecute);
}


/* -------------------------------------------------------------------------- */

void	Form::beSigned(Bureaucrat const &b) {
	if (b.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

/* ------------------------------------ EXCEPTIONS ----------------------------------- */

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<(std::ostream &os, Form	const &obj) {
	os << "Form name: " << obj.getName() << ", status: ";
	if (obj.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << ", grade required to sign: " << obj.getGradeToSign() << ", grade required to excecute: " << obj.getGradeToExecute();
	return (os);
}
