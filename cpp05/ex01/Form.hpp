/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:57:02 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/16 17:51:07 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
private:
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExecute;
public:
	//ocf
	Form();
	Form(Form const &other);
	Form	&operator=(Form const &other);
	~Form();
	//
	Form(std::string &name, bool isSigned, int const gradeToSign, int const gradeToExecute);
	//getters
	std::string	getName() const;
	bool		getSigned() const;
	int const	getGradeToSign() const;
	int const	getGradeToExecute() const;
	//
	void		beSigned(Bureaucrat const &b);
	//exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, Form	const &obj);

#endif