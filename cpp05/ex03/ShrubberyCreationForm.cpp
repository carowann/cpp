/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:46:51 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/18 16:26:22 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ------------------------------------ OCF ----------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

/* -------------------------------------------------------------------------- */

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::ofstream f;
	f.open((_target + "_shrubbery").c_str());
	if (!f.is_open())
		throw (std::runtime_error("Could not open file: " + _target + "_shrubbery"));
	f << "               ,@@@@@@@,\n";
	f << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	f << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	f << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	f << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	f << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	f << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	f << "       |o|        | |         | |\n";
	f << "       |.|        | |         | |\n";
	f << "___ \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	f << std::endl;
	f.close();
}