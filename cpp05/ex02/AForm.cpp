/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:09:33 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/17 11:43:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ------------------------------------ OCF ----------------------------------- */

AForm::AForm() :
	_name("Default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150) {}

AForm::AForm(AForm const &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {}

AForm	&AForm::operator=(AForm const &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

/* -------------------------------------------------------------------------- */

AForm::AForm(std::string const &name, int const gradeToSign, int const gradeToExecute) :
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

std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getIsSigned() const {
	return (_isSigned);
}

int	AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}


/* -------------------------------------------------------------------------- */

void	AForm::beSigned(Bureaucrat const &b) {
	if (b.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

void	AForm::execute(Bureaucrat const &executor) const {
	//if not signed => exception
	if (!_isSigned)
		throw (NotSignedException());
	if (executor.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
}


/* ------------------------------------ EXCEPTIONS ----------------------------------- */

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

const char *AForm::NotSignedException::what() const throw() {
	return ("form is not signed.");
}

/* -------------------------------------------------------------------------- */

std::ostream	&operator<<(std::ostream &os, AForm	const &obj) {
	os << "AForm name: " << obj.getName() << ", status: ";
	if (obj.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << ", grade required to sign: " << obj.getGradeToSign() << ", grade required to excecute: " << obj.getGradeToExecute();
	return (os);
}
