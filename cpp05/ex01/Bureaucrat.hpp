/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:08:25 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/16 17:53:14 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define RED	"\033[0;31m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	//OCF
	Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat	&operator=(Bureaucrat const &other);
	~Bureaucrat();
	//
	Bureaucrat(std::string const &name, int grade);
	//getters
	std::string	getName() const;
	int			getGrade() const;
	//
	void		incrementGrade();
	void		decrementGrade();
	void		signForm();
	//exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &obj);

#endif