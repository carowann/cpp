/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:09:33 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/16 17:51:47 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
/* ------------------------------------ OCF ----------------------------------- */

Form::Form() :
	_name("Default"),
	_isSigned(false),
	_gradeToSign(1),
	_gradeToExecute(1) {}

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

Form::Form(std::string &name, bool isSigned, int const gradeToSign, int const gradeToExecute) :
	_name(_name),
	_isSigned(_isSigned),
	_gradeToSign(_gradeToSign),
	_gradeToExecute(_gradeToExecute) {}

/* ------------------------------------ GETTERS ----------------------------------- */

std::string	Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_isSigned);
}

int const	Form::getGradeToSign() const {
	return (_gradeToSign);
}

int const	Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

/* -------------------------------------------------------------------------- */

// void	Form::beSigned(Bureaucrat const &b);

/* ------------------------------------ EXCEPTIONS ----------------------------------- */

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<(std::ostream &os, Form	const &obj) {
	os << "Form name:" << obj.getName() << ", status (signed): " << obj.getSigned() << ", grade required to sign: " << obj.getGradeToSign() << ", grade required to excecute:" << obj.getGradeToExecute();
	return (os);
}
