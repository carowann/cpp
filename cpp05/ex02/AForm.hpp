/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:57:02 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/17 11:27:57 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExecute;
public:
	//ocf
	AForm();
	AForm(AForm const &other);
	AForm	&operator=(AForm const &other);
	virtual ~AForm();
	//
	AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
	//getters
	std::string		getName() const;
	bool			getIsSigned() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	//
	void			beSigned(Bureaucrat const &b);
	virtual void	execute(Bureaucrat const &executor) const = 0;
	//exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, AForm	const &obj);

#endif